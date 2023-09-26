"""
for i in range(1, 10):
    print(i, "단")
    for j in range(1, 10):
        print(i, "*", j, "=", i*j)
"""
"""
y=lambda x : x*3
y(12)

add=lambda a,b: a+b
add(3,5)
"""

"""
notice = "가나다라마바사아자카"
print(notice[1:5])

notice= lambda x : x[:10]
print(notice)
"""

"""
def multifly(a):
    return a+4
print(multifly(2))
"""

"""
a = input("gd")
print(a)

def aaaa():
    a = int(input("dd:"))
    if (a % 2 == 0):
        print("짝수")
    else:
        print("홀수")
aaaa()
"""

def a():
    s=input("서비스 경로를 입력하세요")
    s1=int(input("부가세를 입력하세요"))
    if(s=="Y"):
        result=