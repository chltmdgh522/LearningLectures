import os

# print(os.getcwd())
# os.chdir('C:/Users/chltm/Desktop/dd/파이썬')
# print(os.listdir())

# folder = os.listdir()
# type(folder)
# print(folder)

# f = open('a.txt', 'w')
# f.write("나는 승호")
# f.close()

# f = open('a.txt', 'r')
# diary = f.read()
# print(diary)

# f = open('news20231010_조선_utf8.txt', 'r',encoding="UTF-8")
# news = f.read()
# print(news)


# 정규표현식
# import re
# result="안녕하세요 저는 ㄷㄷㄷ입니다 안녕히계세요"
# result=re.findall(r'')

# import re
# f = open('news20231010_조선_ansi.txt', 'r')
# news = f.read()
# type(news)

# pattern = r'하마스'
# print(re.match(pattern, news))
# print(re.match(pattern, news).group())

import re
number = "sadfasdf 12121 is 545455"
print(re.findall('\d{6}', number))
