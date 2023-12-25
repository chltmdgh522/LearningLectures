# myBook = 2019, "승호의", "전성기"
# print(type(myBook))
# print(myBook[0])

# myBook = 2
# print(myBook)  # 튜플은 변경 못함


# myBook[0] = 1

# num = [5, 4, 3, 2, 1]
# print(num.remove(2)) #pop은 뜸
# print(num)

# a = [[1, 2, 3, 4], [11, 21, 31, 41]]
# b = a[:]
# b[0][1] = 23
# print(a) #이렇게 하면 바뀜 하지만 b[0]=[1,2,3,4]하면 기존 값 안바뀜

# import copy
# c=copy.deepcopy(a)

# d = [1, 2, 3, 4]
# e = [5, 6]
# d.extend(e)
# print(d)
# del e[1]
# print(e)

# aa = {"승호": 10, "경진": 54}
# aa["승호"] = 13
# aa["민수"] = 13
# print(aa)

# print(aa.keys())
# # del aa["경진"] #이부분만 삭제
# print("승호" in aa)
# # aa.clear() #전체삭제

# for key, value in aa.items():
#     print(key, value)

aaa = {1, 2, 3, 3}
aaa.remove(1)
print(aaa)
