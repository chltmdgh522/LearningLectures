/*#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {
	//fputs("dfsd",fp);

	FILE* fp;
	int num[5];
	int data[5];
	int max = 0;
	int md = 0;
	int index = 0;

	fp = fopen("data.txt", "w");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
		fprintf(fp, "%d\n", num[i]);
	}
	fclose(fp);
	printf("===================================\n");
	int a = 0;
	fp = fopen("data.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%d", &data[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (max < data[i]) {
			max = data[i];
			index = i;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (max> data[i]) {
			if (md < data[i]) {
				md = data[i];
			}
			
		}
	}

	fp = fopen("dataOut.txt", "w");
	fprintf(fp, "max값: %d\nindex 값: %d\n", max,index);
	fprintf(fp, "md값: %d", md);
	fclose(fp);

	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}

	printf("max값: %d\nindex 값: %d\n", max, index);
	printf("md값 %d", md);
	fclose(fp);
}*/