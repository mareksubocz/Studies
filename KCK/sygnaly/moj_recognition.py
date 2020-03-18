from scipy import *
import numpy as np
import matplotlib.pyplot as plt
import os
import wave
import copy
import random
import sys
from warnings import filterwarnings


def kawalki(lista, n):
    for i in range(0, len(lista), n):
        yield lista[i:i + n]


def analyze(file):

    # filterwarnings("ignore")

    # Ze stereo na mono

    audioFile = wave.open(file, 'r')
    signal = audioFile.readframes(-1)
    signal = frombuffer(signal, dtype=np.int16)
    fps = audioFile.getframerate()

    # bez początku i końca po 0.5s - głównie szumy
    signal = signal[fps * 2:-fps * 2]

    fragments = []
    FFTs = []
    globalAvgDistance = 0.0
    count = 0.0

    # for kawalek in kawalki(signal, 10000):
    #     suma = sum(kawalek[kawalek > 0])
    #     if suma > 0:
    #         fragments.append((suma, kawalek))

    for i in range(1, len(signal) - 10001, 10000):
        sum = 0
        for j in signal[i:i + 10000]:
            if j > 0:
                sum += j
        if sum > 0:
            fragments.extend([[sum, signal[i:i + 10000]]])

    fragments.sort(reverse=True)  # loudest-first sorting

    for i in range(5):  # for 5 loudest fragments
        # print(len(fragments))
        if i < len(fragments):  # if present
            FFTnew = []
            FFTs.append(fft(fragments[i][1]))  # calculate FFTs
            FFTs[i] = abs(FFTs[i])
            # (avg signal strength for 0-400Hz)*1.6
            dziwna_wartosc = int((400.0 / fps) * 10000)
            FFTavg = np.mean(FFTs[i][:dziwna_wartosc]) * 1.6
            # remove peaks under FFTavg
            for ind, val in enumerate(FFTs[i][:dziwna_wartosc]):
                if val < FFTavg:
                    FFTnew.append(0)
                else:
                    FFTnew.append(val)

            maxes = []
            for i in range(0, len(FFTnew)):  # looking for local maximums
                if i + 6 < len(FFTnew):
                    if FFTnew[i] < FFTnew[i + 1] and FFTnew[i + 1] > FFTnew[i + 2]:
                        maxes.append(i + 1)

            maxesNew = copy.copy(maxes)  # removing doubled maximums
            for i in range(len(maxes) - 1):
                if maxes[i + 1] - maxes[i] < 9:
                    maxesNew.remove(maxes[i + 1])

            avgDistance = 0.0
            if (len(maxesNew) > 1):  # calculating average distances between harmonics for the fragment
                count += 1
                for i in range(len(maxesNew) - 1):
                    avgDistance += maxesNew[i + 1] - maxesNew[i]
                avgDistance /= float(len(maxesNew) - 1)
                globalAvgDistance += avgDistance

    if count > 0:
        # calculating average distances between harmonics for all fragments
        globalAvgDistance /= float(count)
    else:
        globalAvgDistance = random.uniform(10, 40)

    if (globalAvgDistance < 23 and file[-5] == 'M') or (globalAvgDistance >= 23 and file[-5] == 'K'):
            # print("M")
        return True, globalAvgDistance
    else:
        return False, globalAvgDistance
    # else:
        # print("F")
        # print(globalAvgDistance)
    return globalAvgDistance


if __name__ == "__main__":
    distsM = []
    distsF = []
    total_result = 0
    if(sys.argv[1] == "all"):
        for file in os.listdir('trainall'):
            result, gad = analyze('trainall/' + file)
            if(file[-5] == 'M'):
                distsM.append(gad)
            else:
                distsF.append(gad)
            if result:
                total_result += 1
        # plt.plot(distsM, [1] * len(distsM), 'o', color='blue')
        # plt.plot(distsF, [1] * len(distsF), 'o', color='red')
        # plt.show()
        print(total_result)
    else:
        analyze(sys.argv[1])
