"""
alist=["A","B","C"]
blist=alist
blist[0]="a"
print(alist) #참조 연결되서 둘이 똑같음 자바는 안그러는데.. 신기.! 
clist=list(alist) #참조 연결 아니고 값만 복사해줌
clist[1]="Aa"
print(alist)
dlist=alist[:] #얘도 값만 복사!
print(dlist)

for i  in alist:
    print(i)  #for문 예시 자바의 향상된 for이랑 비슷한듯 
"""
"""
numbers=[1,2,3,4,5]
numbers.reverse() 
print(numbers)
numbers.sort()
a=sorted(numbers,reverse=False) #True면 내림차순
print(a)
"""
"""
a=["a,b,c,d","dc","e"]
print([s.upper() for s in a])
b_first=[b[0].upper() for b in a]
print(b_first)
"""

"""
y=[x for x in range(10) if x %2==0]
print(y)
print([x**2 for x in range(10) if x %2==0]) #맨앞이 마지막 if가 2번쨰로 실행
"""
"""
s=["a","1","b","2"]
numbers=[x for x in s if x.isdigit()] #문자열중에 정수로 된거 반환 근데 정수 문자열 섞여있으면 못쓰는듯
print(numbers)
"""
"""
num=[ int(x) for x in input("정수입력").split() if x.isdigit] 
print(num)
"""
num1=[(x,y) for x in [1,2,3] for y in [4,5,6]]
print(num1)

