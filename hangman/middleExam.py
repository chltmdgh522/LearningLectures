import random
languages_a = {'C', 'JavaScript', 'Python', 'R', 'Swift', 'Kotlin'}
languages_b = {'C++', 'Java', 'Python', 'C#', 'JavaScript', 'R'}

print(languages_a & languages_b)

print((languages_a ^ languages_b)-languages_b)
print((languages_b ^ languages_a)-languages_a)

print(len(languages_a)+len(languages_b))


scores = dict()
for i in range(10, 50):
    scores['S' + str(i)] = random.randrange(50, 100)


score = 0
cnt = 0
for value in scores.values():
    score += value
    cnt += 1
print(score/cnt)

max_value = 0
max_key = 0
for key, value in scores.items():
    if max_value < value:
        max_value = value
        max_key = key
    elif max_value == value:
        if max_key < key:
            max_value = value

print(max_key, max_value)
