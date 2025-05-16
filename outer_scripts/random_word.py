import random

with open(file="word/3500_new.txt", mode="r") as file:
    words = file.read().strip().splitlines()

words_random = random.sample(words, 1000)

for word in words_random:
    print(word)

with open(file="word/1000_random.txt", mode="w") as file:
    for word in words_random:
        file.write(word + "\n")