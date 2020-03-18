import sys
import os
import matplotlib.pyplot as plt
import numpy as np
from soundfile import read
from statistics import mean
from scipy import argmax
from numpy.fft import rfft, fftfreq
from copy import copy
from warnings import filterwarnings


def hps(spectrum, fps):

    freqs = abs(fftfreq(len(spectrum)) * fps)
    spectrum[freqs < 70] = 0  # usuwamy za małe
    max_divisor = 6

    # result = 0
    hps = copy(spectrum)
    for x in range(2, max_divisor):
        decimated = copy(spectrum[::x])
        hps = hps[:len(decimated)]
        wynik = argmax(hps)
        # result = fps * wynik / len(spectrum)
        # print(f'Pętla {x}: {result}')
        hps *= decimated

    return fps * argmax(hps) / len(spectrum)


def analyze(file):

    signal, fps = read(file)
    signal = np.asarray(signal)
    if len(signal.shape) == 2:  # Ze stereo na mono
        signal = signal.sum(axis=1) / 2

    signal = signal * np.kaiser(len(signal), 15)  # uwydatnienie górek
    signal = abs(rfft(signal))  # ramkowe fft

    return hps(signal, fps)


if __name__ == "__main__":
    try:
        filterwarnings("ignore")

        # distsM = []
        # distsF = []
        # total_result = 0
        # result = True
        # if(sys.argv[1] == "all"):
        #     for i, file in enumerate(os.listdir('trainall')):
        #         print(i)
        #         gad = analyze('trainall/' + file)
        #         if(file[-5] == 'M'):
        #             distsM.append(gad)
        #             if gad < 340:
        #                 result = True
        #             else:
        #                 result = False
        #         else:
        #             if gad >= 340:
        #                 result = True
        #             else:
        #                 result = False
        #             distsF.append(gad)
        #         if result:
        #             total_result += 1
        #     plt.plot(distsM, [2] * len(distsM), 'o', color='blue')
        #     plt.plot(distsF, [1] * len(distsF), 'o', color='red')
        #     plt.xlim(40, 500)
        #     plt.show()
        #     print(total_result)
        result = analyze(sys.argv[1])
        if result < 340:
            print('M')
        else:
            print('K')
    except:
        print('M')
