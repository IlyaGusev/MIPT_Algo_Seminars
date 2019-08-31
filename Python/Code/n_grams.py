from collections import Counter, defaultdict
import numpy as np

n = 4
n_grams = [Counter() for _ in range(n+1)]
model = defaultdict(dict)
with open("wp.txt", "r", encoding="utf-8") as f:
    for line in f:
        words = line.strip().lower().split(" ")
        for current_n in range(1, n+1):
            l = [tuple(words[i: i+current_n]) for i in range(len(words)-current_n+1)]
            n_grams[current_n].update(l)
        
for words, count in n_grams[n].items():
    context = tuple(words[:-1])
    context_count = n_grams[n-1][context]
    model[context][words[-1]] = count / context_count

words = ["?????", "??????", "????????"]
for i in range(50):
    context = tuple(words[-n+1:])
    proba = model[context]
    s = sum(proba.values())
    proba = {key: p/s for key, p in proba.items()}
    new_word = np.random.choice(list(proba.keys()), size=1, p=list(proba.values()))[0]
    words.append(new_word)
print(" ".join(words))