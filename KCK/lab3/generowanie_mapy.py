import matplotlib.pyplot as plt
from gradienty import gradient_hsv_bw
import matplotlib.colors
from math import sin


def gradient_hsv_custom(v):
    return sin(v), 1-v, 1


norm = matplotlib.colors.Normalize(-1, 1)
colors = [[norm(-1.0), "green"],
          [norm(0.0), "yellow"],
          [norm(1.0), "red"]]

cmap = matplotlib.colors.LinearSegmentedColormap.from_list("", colors)

image = []
with open('big.dem') as file:
    for i, line in enumerate(file):
        if i == 0:
            continue
        image.append([])
        for j, height in enumerate(line.split()):
            plt.plot(i, j, color=float(height))
    # plt.hsv()
    # plt.imshow(image, cmap=gradient_hsv_custom)
    plt.show()
