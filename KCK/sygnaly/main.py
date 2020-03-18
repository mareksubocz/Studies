
signalK = data[1][lMargin:]kaiser(len(signal), 100)
for p in arange(2, 6):
    d = decimate(fft_data, p)
# decimate() dla dzielenia synałuq
