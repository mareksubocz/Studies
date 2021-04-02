from bitarray import bitarray
from collections import defaultdict
from math import log2, ceil

def create(d: dict):
    result = {}
    length = ceil(log2(len(d)))
    # sort from most frequent to least
    d = {k: v for k, v in sorted(d.items(), key=lambda item: -item[1])}
    iterator = 0
    for key, value in d.items():
        result[key] = format(iterator, f'0{length}b')
        iterator += 1
    return result


def encode(text, code):
    result = bitarray()
    for c in text:
        result += code[c]
    return result

def decode(text, code):
    length = ceil(log2(len(code)))
    text = [text[i:i+length] for i in range(0, len(text), length)]
    reversed_code = {v: k for k, v in code.items()}
    result = ''
    for chunk in text:
        if chunk in reversed_code:
            result += reversed_code[chunk]
    return result

def save(coded_text, code, path, codepath):
    with open(codepath, "w") as file:
        file.write(str(code))
    with open(path, "wb") as file:
        coded_text.tofile(file)

def load(path, codepath):
    with open(codepath) as file:
        code = file.read()
    result = bitarray()
    with open(path, "rb") as file:
        result.fromfile(file)
    return result.to01(), eval(code)


with open('./norm_wiki_sample.txt') as file:
    d = defaultdict(int)
    text = file.read()
    for c in text:
        d[c] += 1
    code_to_save = create(d)
    coded_text_to_save = encode(text, code_to_save)
    save(coded_text_to_save,code_to_save, "result.bin", "result_code.txt")
    coded_text, code = load("result.bin", "result_code.txt")
    decoded_text = decode(coded_text, code)
    print(text[-60:])
    print(code)
    print(decoded_text[-60:])
    if text == decoded_text:
        print('Tekst oryginalny i odkodowany są takie same.')
    else:
        print('Tekst oryginalny i odkodowany różnią się.')
