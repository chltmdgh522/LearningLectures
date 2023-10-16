# 생성다항식을 비트로 바꿔주는 과정
def newdahang(a):
    word_list = a.split("+")
    x = word_list[0]
    binary = 1
    result = 0
    for word in word_list:
        x = word
        if x.count("x") == 1:
            s = x[1:]
            if s:
                for i in range(int(s)):
                    binary *= 10
            else:
                binary *= 10
            result += binary
            binary = 1
        else:
            result += 1
    return result


# 00을 붙인 원래데이터
def orginalData(binary, data):
    b_len = len(str(binary))-1
    s_data = str(data)
    for i in range(b_len):
        s_data += "0"
    return s_data


# 체크섬 구하기
def checkSum(binary, data):
    str_data = str(data)
    str_binary = str(binary)
    copyStr_data = str_data  # 원본데이터 훼손 안하기 위해서

    for i in range(0, len(str_data[len(str_binary):])+1):  # 나누기 횟수 구할려고
        start_data = int(copyStr_data[0:1])  # 앞자리 구해서 계산해줄려고
        if start_data == 1:
            final = str_binary  # 앞자리 1일때 binay 값을 final 대입
        else:
            final = "0" * len(str_binary)  # 앞자리 0일때 binary 길이만큼 0으로 초기화
        if (i == 0):
            calc_data = copyStr_data[0:len(final)]
        else:
            calc_data = copyStr_data  # 맨 처음과 구분해주기 위해 작성

        result = format(int(calc_data, 2) ^ int(
            final, 2), '0' + str(len(final)) + 'b')  # XOR 연산자

        result_r = str(result)
        # XOR로 계산된 데이터를 앞자리 제거하고 원본데이터에 한자리를 뒤에 추가
        f_result = result_r[1:]+str_data[i+len(str(final)):i+len(str(final))+1]
        copyStr_data = f_result  # 다시 copy에다가 저장

    return copyStr_data


a = input("생성 다항식을 입력하세요: ")
b = input("원래 데이터를 입력하세요: ")
binary = newdahang(a)  # 생성 다항식을 이진수로 구하는 함수
data = orginalData(binary, b)  # 00을 붙인 추가된 데이터를 구하는 함수
result_checkSum = checkSum(binary, data)  # 체크섬 구하기
print("체크섬:", result_checkSum)
