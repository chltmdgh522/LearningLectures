# t = "money python"
# a = t[:-2]
# print(a)

# s = "Welcome, to,   Python, and ,   bla,  bla    "
# a = [x.strip() for x in s.split(',')]  # 양쪽 공백 제거
# print(a)

# print(list("hello, world!"))

# a = 'gd'.join(['apple', 'grpae', 'banana']) #각 사이마다 gd랑 연결
# print(a)

# print('123.123.123123'.replace('.', '-'))

# a_string = 'Action \n\t speak louder than words'
# word_list = a_string.split()
# print(word_list)
# a = ' '.join(word_list)
# print(a) #문자열중에서 필요없는 공백 제ㅐ거

# s = '########this is an example#########'
# s.lstrip('#') #앞에 #제거
# s.rsplit('#') #뒤에 #제거
# a = s.strip('#').capitalize() #다 제거후 문장의 첫글자를 대문잠로 만듬
# print(a)

# s='www.booksr.co.kr'
# print(s.find('.kr'))#해당 문자열 첫 인덱스 반환 없으면 -1반환
# print(s.count('.'))#.카운ㄷ트수 반환
# print(ord(max(s)))#유니코드 값이 가장 큰 값의 유니코드값을 반환

# import string
# src_str = string.ascii_uppercase
# print(src_str) #String 모듈 지원

# t = "a a a a a"
# print(t.count(' '))
# print(len(t.split()))

# t = "SDFLJASDFJL  abc ASDF def JASDLF"
# alist = ["abc", "def"]
# a=t.lower()
# for i in alist:
#     a = a.replace(i, '*')
# print(a)

t = "asdfja!sdf  A DF a!sdf aA asd!!"
t1 = t.count("!")
cnt = 0
a = list(t)
for i in a:
    if (i.isupper()):
        cnt += 1

print(cnt)
