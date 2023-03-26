#include <stdio.h>
#include <stdlib.h>
void insert(int** arr, int* size, int index, int value) {
	*arr = (int*)realloc(*arr, (*size + 1) * sizeof(int));  // 메모리 크기 확잧
	for (int i = *size; i > index; i--) {  // 인덱스 이후 요소들을 한 칸씩 뒤로 이동
		(*arr)[i] = (*arr)[i - 1];
	}
	(*arr)[index] = value;  // 인덱스 위치에 새로운 값 추가
	*size += 1;  // 배열 크기 증가
}

int main() {
	int* arr = (int*)malloc(5 * sizeof(int));  // 5개의 int형 배열 할당
	int size = 5;  // 배열 크기 초기화

	// 배열 초기화
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}

	
	insert(&arr, &size, 2, 7);  //insert함수 추가 및 인덱스 2에 값 10 삽입
	printf("chage array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}







	/*	int data[10];
	int num;
	int a = 0;
	int cnt = 1;
	printf("정수 10개를 입력하세요");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}

	while(cnt) {
		printf("\n찾고싶은 정수1개를 입력하세요");
		scanf("%d", &num);
		for (int j = 0; j < 10; j++) {
			if (num == data[j]) {
				a++;
				printf("%d은 %d번째 자리에 있습니다.\n", num, j+1);
				break;
			}
			if (j == 9) {
				if (a == 0) {
					printf("No exist!!\n");
				}
				
			}
			
		}
		
		printf("계속하고싶으면 1 안하고싶으면 0입력하세요");
		scanf("%d", &cnt);
	}
*/

/*char name[10];
	char num[10];
	int i = 1; 

	while(1){

	printf("학번을 입력하세용\n");
	scanf("%s", num);

	printf("이름을 입력하세용\n");
	scanf("%s", name);
	
	printf("학번: %s \n이름: %s\n", num, name);
	
	printf("안할거면 0을 입력하세용");
	scanf("%d", &i);
	if (i == 0) {
		break;
	}
	}*/