"""
phone_book = {}  # 딕셔너리 생성
phone_book["승호"] = "111"
phone_book["승"] = "111"

print(phone_book)

print(phone_book.keys())  # 키 값
print(phone_book.values())  # value 값


print(phone_book.items())
for n, p in phone_book.items():
    print(n, ':', p)

for key in phone_book.keys():
    print(key, ':', phone_book[key])  # 이런 경우 많이씀

sorted_a = sorted(phone_book.items(), key=(lambda x: x[0]))
print(sorted_a)

del phone_book["승호"]
print(phone_book)

t = (1, 2, 3)
print((lambda x: x[0])(t))
"""

"""
items = {"가": 4, "나": 2}
a = input("물건의 이름을 입력하시오:")
print(items[a])
"""

"""

print(set([1, 2, 3, 3]))  # 집합은 중복된게 있으면 안됨 , 또한 인덱스가 업어서 접근할 수 없음
numbers = set()  # 비어있는 집합

A = {1, 2, 3, 5, 4, 5}
B = {1, 2, 3, 4, 5}
print(A > B)  # 진부분 집합 인지 부분집합인지 = 있으면 크기가 같을때 트루! 

all(A) # 0이 있으면 false
any(A) # 0이 있으면 true

print(A | B) # 합집합
print(A.union(B)) # 합집합

print(A & B) # 교집합
print(A.intersection(B)) # 교집합

print(A - B) # 차집합
print(A.difference(B)) # 차집합
"""


def soulution(num):
    numbers = set()
    for i in range(2, num):
        if (num % i == 0):
            numbers.add(i)
    return numbers


a = 48
b = 60
A = soulution(a)
B = soulution(b)

print(max(A.intersection(B)))  # 최대 공약수 구하기
