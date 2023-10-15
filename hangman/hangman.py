correct_word = "abcdef"

my_list = [0] * len(correct_word)
cnt = 10
f_cnt = 0

while (cnt != 0):
    print("기회:" + str(cnt) + "번")
    print("현재 단어창:", my_list)
    word = input("단어 한글자를 입력하세요: ")
    if (correct_word.find(word) == -1):
        print("단어가 없습니다.")
        cnt -= 1
    else:
        f_cnt += 1
        correct = correct_word.find(word)
        word = correct_word[correct:correct+1]
        my_list[correct] = word
        if (f_cnt == len(correct_word)):
            print("수고하셨습니다.")
            break
