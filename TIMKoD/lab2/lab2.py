from random import randint, choices
from collections import defaultdict
from tqdm import tqdm

# zadanie 1
# for i in range(100):
#     tmp = randint(96, 122)
#     if tmp == 96: tmp = 32
#     print(chr(tmp), end='')

def generate_dictionary(s: str, markov: int):
    d = defaultdict(int)
    for i in range(len(s) - markov):
        phrase = s[i:i+markov+1]
        d[phrase] += 1
    return d

def get_next_character(d: dict, s: str):
    phrases = []
    weights = []
    for key, value in d.items():
        if key.startswith(s):
            phrases.append(key)
            weights.append(value)
    return choices(phrases, weights=weights)[0][-1]

def generate_beginning(s: str, markov: int):
    result = ''
    for m in range(markov):
        d = generate_dictionary(s, m)
        result += get_next_character(d, result)
    return result


# zadanie 4
markov = 5
num_of_chars = 1000
with open("dane/norm_wiki_sample.txt") as file:
    source_text = ''
    result = ''
    for row in file:
        source_text += row
    result = generate_beginning(source_text, markov)
    # zaczynamy słowem probability
    result = 'probability'
    print('generating dictionaries...')
    d = generate_dictionary(source_text, markov)
    for i in tqdm(range(num_of_chars)):
        c = get_next_character(d, result[-markov:])
        result += c
    print('')
    print(f'Źródło: łańcuch Markova {markov}. stopnia')
    print('')
    print(result)
    print('')
    words = result.split(' ')
    from statistics import mean
    mean_length = mean([len(w) for w in words])
    print(f'mean_length: {mean_length}')


