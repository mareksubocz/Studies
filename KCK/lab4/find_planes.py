from glob import glob
from random import randint
from statistics import mean

import cv2
import numpy as np
from skimage.exposure import rescale_intensity

for path in glob("planes/*.jpg"):
    image = cv2.imread(path)
    image = cv2.resize(image, (500, 500))
    image_blue = image[:, :, 0]
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    gray_image = image_blue
    p2, p98 = np.percentile(gray_image, (0.5, 90))
    gray_image = rescale_intensity(gray_image, in_range=(p2, p98))
    gray_image = cv2.bilateralFilter(gray_image, 9, 75, 75)

    canny_image = cv2.Canny(gray_image, 100, 200)
    cv2.namedWindow("Canny", cv2.WINDOW_AUTOSIZE)
    cv2.moveWindow('Canny', 100, 100)
    cv2.imshow('Canny', canny_image)

    contours, _ = cv2.findContours(canny_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    hull = []
    for contour in contours:
        hull.append(cv2.convexHull(contour, False))
    blank = np.zeros((500, 500))
    cv2.fillPoly(blank, pts=hull, color=(1))

    kernel = np.ones((5, 5), np.uint8)
    img_dilation = cv2.dilate(blank, kernel, iterations=2)
    img_dilation = cv2.erode(img_dilation, kernel, iterations=1)

    img_dilation = np.array(img_dilation, dtype=np.uint8)
    contours_filled, _ = cv2.findContours(img_dilation, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    hull_filled = []
    for contour in contours_filled:
        hull_filled.append(cv2.convexHull(contour, False))
    hull_filled = contours
    for j, contour in enumerate(hull_filled):
        x_mean = int(mean([x[0][0] for x in contour]))
        y_mean = int(mean([x[0][1] for x in contour]))

        area = cv2.contourArea(contour)

        # if area > 2:
        color = (randint(0, 255), randint(0, 255), randint(0, 255))
        img2 = cv2.drawContours(image, hull_filled, j, color, 3)
        img2 = cv2.circle(img2, (x_mean, y_mean), 2, color, 2)

    cv2.namedWindow("End", cv2.WINDOW_AUTOSIZE)
    cv2.imshow('End', img2)
    cv2.moveWindow('End', 600, 100)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
