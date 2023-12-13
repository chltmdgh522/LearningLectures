import re
import csv
import os

import user1

# # 모듈로 불러오기
# os.chdir(r"C:\Users\chltm\Desktop\파이썬")
# total = user1.opencsv("pop.csv")
# for i in total[:5]:
#     print(i)

i = ["123!!", "151,767", "11,093", "27,394", '']
for j in i:
    try:
        if re.search(r'[a-z가-힣!]', j):
            i[i.index(j)] = j
        else:
            i[i.index(j)] = float(re.sub(r',', '.', j))

    except:
        pass

# 모듈 관리
os.chdir(r"C:\Users\chltm\Desktop\파이썬")
a = [["국어", "수학"], ["87", "55"]]
user1.writecsv("test.csv", a)


os.chdir(r"C:\Users\chltm\Desktop\파이썬")
f = open("a.csv", "r", encoding="UTF-8")

new = csv.reader(f)

for i in new:
    print(i)

a_list = []
for i in new:
    a_list.append(i)
print(a_list)

f.close()


print(user1.opencsv("a.csv"))

# print(opencsv("a.csv"))
# a = [["성명", "파이썬", "빅데이터"], ["D", 80, 90], [
#     "C", 100, 98], ["B", 98, 88], ["A", 88, 74]]


# f = open("abc.csv", "w", newline="")
# csvObject = csv.writer(f, delimiter=',')
# csvObject.writerows(a)
# f.close()


# def writecsv(filename, the_list):
#     f = open(filename, "w", newline="")
#     csvob = csv.writer(f, delimiter=",")
#     csvob.writerows(the_list)
#     f.close()
#     return csvob


writecsv("a2.csv", a)

total = [1, 2, 3]
total += [4]
print(total)
print(total.index(1))
