#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {

	FILE* fp;
	int num[20];
	int data[20];
	int max = 0;
	int index = 0;
	int temp = 0;

	fp = fopen("data.txt", "w");
	for (int i = 0; i < 20; i++) {
		scanf("%d", &num[i]);
		fprintf(fp, "%d\n", num[i]);
	}
	fclose(fp);
	printf("===================================\n");
	int a = 0;
	fp = fopen("data.txt", "r");
	for (int i = 0; i < 20; i++) {
		fscanf(fp, "%d", &data[i]);
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}


	fp = fopen("dataOut.txt", "w");
	

	printf("정렬된 값: ");
	for (int i = 0; i < 20; i++) {
		fprintf(fp, "%d", data[i]);
		printf("%d ", data[i]);
	}
	fclose(fp);
}