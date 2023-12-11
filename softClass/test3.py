from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
import pandas as pd

# 전체 데이터를 전처리
processed_data = [
    {'country': 'USA', 'destination': 'Beach', 'age': '20대',
        'companion': 'Family', 'preference': 4},
    {'country': 'France', 'destination': 'City', 'age': '20대',
        'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},

    {'country': 'France', 'destination': 'City', 'age': '30대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},
    {'country': 'France', 'destination': 'City', 'age': '20대',
     'companion': 'Friends', 'preference': 2},

]

# 전처리된 데이터를 특성과 레이블로 분리
X = pd.DataFrame(processed_data, columns=[
                 'country', 'destination', 'age', 'companion', 'preference'])
y = (X['preference'] >= 3).astype(int)  # preference가 3 이상인 경우 1, 아니면 0으로 변환

# 원핫 인코딩 적용
X_encoded = pd.get_dummies(
    X, columns=['country', 'destination', 'age', 'companion'])
X_encoded = X_encoded.astype(int)
print(X_encoded.columns)

# 데이터를 학습 및 테스트 세트로 분할
X_train, X_test, y_train, y_test = train_test_split(
    X_encoded, y, test_size=0.2, random_state=42)

# 모델 초기화 및 학습
model = LogisticRegression()
model.fit(X_train, y_train)


# 모델 평가
y_pred_prob = model.predict_proba(X_test)[:, 1]  # 클래스 1에 속할 확률
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f'Accuracy: {accuracy}')
print(model)
