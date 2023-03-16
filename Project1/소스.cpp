#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main (void) {
	
	int data[10];
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
}

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