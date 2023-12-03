import pandas as pd
import matplotlib.pyplot as plt

url = "C:/Users/chltm/Downloads/서울시 관광 명소.csv"
data = pd.read_csv(url, encoding='cp949')

language_distribution = data['언어'].value_counts()
print("언어 분포:\n", language_distribution)

if '운영시간' in data.columns:
    data['운영시간_count'] = data['운영시간'].apply(
        lambda x: len(str(x).split(',')) if pd.notna(x) else 0)
    data['운영시간_count'].value_counts().sort_index().plot(kind='bar')
    plt.title('운영시간 분포')
    plt.xlabel('운영시간 수')
    plt.ylabel('명소 수')
    plt.show()

if '휴무일' in data.columns:
    day_off_distribution = data['휴무일'].value_counts()
    print("휴무일 분포:\n", day_off_distribution)


if '교통정보' in data.columns:
    transportation_info_distribution = data['교통정보'].value_counts()
    print("교통정보 분포:\n", transportation_info_distribution)
