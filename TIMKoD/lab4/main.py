# entropy(X) = -sum( p(xi) * log2(p(xi)) )
# cond_entropy(X) = -sum( p(x,y) * log2(p(x|y)) )

from collections import defaultdict
from math import log2
import os


class PhraseInfo:
    def __init__(self):
        self.num = 0
        self.followups = defaultdict(int)

    def add_followup(self, followup):
        self.num += 1
        self.followups[followup] += 1

    def calculate_conditional_entropy(self, num_sum):
        self.num /= num_sum
        followups_sum = sum(self.followups.values())
        entropy = 0
        for value in self.followups.values():
            p = value / followups_sum
            entropy += self.num * p * log2(p)
        return entropy


def calculate_entropy(s: list, degree: int, separator: str):
    phrases = defaultdict(PhraseInfo)

    for i in range(len(s) - degree):
        phrase = separator.join(s[i:i+degree])
        followup = s[i+degree]
        # if phrase not in phrases:
        #     phrases[phrase] = PhraseInfo()
        phrases[phrase].add_followup(followup)

    # normalize probabilities
    phrases_sum = sum([p.num for p in phrases.values()])
    entropy = 0
    for phrase in phrases.values():
        entropy -= phrase.calculate_conditional_entropy(phrases_sum)

    return entropy


max_degree = 5
# for filename in os.listdir('./dane'):
    # print(f"OTWIERAM PLIK {filename}")
with open('dane/sample4.txt') as file:
    source_text = ''
    for row in file:
        source_text += row[:-1]

    # letters
    print("LETTERS")
    for degree in range(max_degree):
        result = calculate_entropy(source_text, degree, '')
        print(f"{result} for degree {degree}")

    # words
    print("WORDS")
    source_text_words = source_text.split(' ')
    for degree in range(max_degree):
        result = calculate_entropy(source_text_words, degree, ' ')
        print(f"{result} for degree {degree}")
