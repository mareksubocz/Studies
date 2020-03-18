from __future__ import division

import matplotlib.pyplot as plt
import numpy as np
from matplotlib import colors, rc
from matplotlib.colors import hsv_to_rgb
from math import sin
# matplotlib.use('Agg')


def plot_color_gradients(gradients, names):
    rc('legend', fontsize=10)

    column_width_pt = 400
    pt_per_inch = 72
    size = column_width_pt / pt_per_inch

    fig, axes = plt.subplots(nrows=len(gradients), sharex=True,
                             figsize=(size, 0.75 * size))
    fig.subplots_adjust(top=1.00, bottom=0.05, left=0.25, right=0.95)

    for ax, gradient, name in zip(axes, gradients, names):
        # Create image with two lines and draw gradients on it
        img = np.zeros((2, 1024, 3))
        for i, v in enumerate(np.linspace(0, 1, 1024)):
            img[:, i] = gradient(v)

        im = ax.imshow(img, aspect='auto')
        im.set_extent([0, 1, 0, 1])
        ax.yaxis.set_visible(False)

        pos = list(ax.get_position().bounds)
        x_text = pos[0] - 0.25
        y_text = pos[1] + pos[3]/2
        fig.text(x_text, y_text, name, va='center', ha='left', fontsize='10')

    # fig.savefig('my-gradients.pdf')
    plt.show()


def hsv2rgb(h, s, v):
    return hsv_to_rgb([h, s, v])


def gradient_rgb_bw(v):
    return (v, v, v)


def gradient_rgb_gbr(v):
    if v <= .5:
        v *= 2
        return 0, 1 - v, v
    v = (v - .5) * 2
    return v, 0, 1 - v


def gradient_rgb_gbr_full(v):
    if v <= .25:
        v *= 4
        return 0, 1, v
    elif v <= .5:
        v = (v - .25) * 4
        return 0, 1 - v, 1

    elif v <= .75:
        v = (v - .5) * 4
        return v, 0, 1  # odwróc
    v = (v - .75) * 4
    return 1, 0, 1 - v


def gradient_rgb_wb_custom(v):
    if v <= 1/7:
        v *= 7
        return 1, 1-v, 1
    elif v <= 2/7:
        v = (v - 1/7) * 7
        return 1-v, 0, 1
    elif v <= 3/7:
        v = (v - 2/7) * 7
        return 0, v, 1
    elif v <= 4/7:
        v = (v - 3/7) * 7
        return 0, 1, 1-v
    elif v <= 5/7:
        v = (v - 4/7) * 7
        return v, 1, 0
    elif v <= 6/7:
        v = (v - 5/7) * 7
        return 1, 1-v, 0
    v = (v - 6/7) * 7
    return 1-v, 0, 0


def gradient_hsv_bw(v):
    return hsv2rgb(0, 0, v)


def gradient_hsv_gbr(v):
    v *= 2/3
    v += 1/3
    return hsv2rgb(v, 1, 1)


def gradient_hsv_unknown(v):
    v *= 0.35
    v += 0.65
    return hsv2rgb(1-v, 0.5, 1)


def gradient_hsv_custom(v):
    return hsv2rgb(sin(v), 1-v, 1)


if __name__ == '__main__':
    def toname(g):
        return g.__name__.replace('gradient_', '').replace('_', '-').upper()

    gradients = (gradient_rgb_bw, gradient_rgb_gbr, gradient_rgb_gbr_full,
                 gradient_rgb_wb_custom, gradient_hsv_bw, gradient_hsv_gbr,
                 gradient_hsv_unknown, gradient_hsv_custom)

    plot_color_gradients(gradients, [toname(g) for g in gradients])
