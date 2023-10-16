from operator import itemgetter

f = open("alphabet.txt", "r")
dir = f.read()

# 대소문자 무시하기위해서 소문자로 전부 바ㅏ꿈
f_dir = dir.lower()

# 키 값 생성위해 딕셔너리 생성
alphabet_count = {}

# 알파벳수를 딕셔너리에 저장
for i in range(0, 26):
    cnt = 0
    cnt = dir.count(chr(i+97))
    alphabet_count[chr(i+97)] = cnt

f.close()

# 딕셔너리 값을 기준으로 오름차순 정렬
sorted_alphabet_count = dict(sorted(alphabet_count.items(), key=itemgetter(1)))

# 오름차순 정렬된 값을 갖고 파일 저장
f = open("sorted.txt", "w")
for alphabet, cnt in sorted_alphabet_count.items():
    f.write(f"{alphabet}: {cnt}개")
    f.write("\n")
f.close()

# 정렬된 값에 a b c d e 부여 즉 문장안에서 젤 적은 수가 j인데 이거를 a,  q:b, z:c ......
cnt = 0
for key, i in sorted_alphabet_count.items():
    sorted_alphabet_count[key] = chr(cnt+97)
    cnt += 1


# 정렬된 기준으로 원래문장을 암호문으로 변경
f = open("alphabet.txt", "r")
dir = f.read()
f1 = open("password.txt", "w")
for word in dir:
    # 대문자를 해결하기위해
    if 'A' <= word <= 'Z':
        u_word = sorted_alphabet_count.get(word.lower(), word)
        f1.write(u_word.upper())
    else:
        f1.write(sorted_alphabet_count.get(word.lower(), word))
f1.close()
f.close()


# 암호문을 원래 문장으로 변경
replace_alphabet = {}
for key, value in sorted_alphabet_count.items():
    replace_alphabet[value] = key

f2 = open("orginal_alphabet.txt", "w")
f1 = open("password.txt", "r")
password_dir = f1.read()

for word in password_dir:
    # 대문자를 해결하기위해
    if ('A' <= word <= 'Z'):
        u_r_word = replace_alphabet.get(word.lower(), word)
        f2.write(u_r_word.upper())
    else:
        f2.write(replace_alphabet.get(word.lower(), word))

f1.close()
f2.close()
