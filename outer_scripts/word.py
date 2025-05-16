with open(file="word/3500.txt", mode="r") as file:
    words_raw = file.read().strip().splitlines()

words = []
words_new = []

i = 0
for word in words_raw:
    if i % 3 == 0:
        words.append(word)
    i += 1

for word in words:
    cont = False

    if word.endswith(" "):
        word = word[:-1]

    # 只要由小写字母构成的单词
    for letter in word:
        if letter not in ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]:
            cont = True
            break
    
    # 添加到最终列表
    if not cont:
        words_new.append(word)

for word in words_new: print(word)

with open(file="word/3500_new.txt", mode="w") as file:
    for word in words_new:
        file.write(word + "\n")
