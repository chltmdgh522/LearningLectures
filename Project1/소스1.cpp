/*#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int dataA[10];
	int dataB[20];
	int i, n;
	printf("A 10개 B 20개입력하세요");
	for (i = 0; i < 30; i++) {
		scanf("%d", &n);
		if (i < 10) {
			dataA[i] = n;
		}
		if (i == 9){
			printf("이젠 B입력");
		}
		else if(i<30) {
			dataB[i-10] = n;
		}
	}
	for (i = 0; i < 30; i++) {
		if(i<10){
		printf("%d ", dataA[i]);
		}
		if (i == 9) {
			printf("\n");
		}
		else if(i<30) {
			printf("%d ", dataB[i-10]);
		}
	}
	printf("\n");
	int input,a=1;
	while (a) {
		printf("안하고 싶으면 0 and는 1 or은 2 입력하세요\n");
		scanf("%d", &input);
		if (input == 1) {
			for (i = 0; i < 10; i++) {
				printf("%d ", dataA[i] & dataB[i]);
			}
		}
		else if (input == 2) {
			for (i = 0; i < 10; i++) {
				printf("%d ", dataA[i] | dataB[i]);
			}
		}
		else if (input == 0) {
			a = 0;
		}
	}
}*/