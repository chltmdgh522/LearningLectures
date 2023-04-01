#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {

	FILE* fp;
	int num[5];
	int data[20];
	int max = 0; 
	int index = 0;

	fp = fopen("data.txt", "w");
	for (int i = 0; i < 20; i++) {
		scanf("%d",&num[i]);
		fprintf(fp, "%d\n", num[i]);
	}
	fclose(fp);
	printf("===================================\n");
	int a = 0;
	fp = fopen("data.txt", "r");
	for (int i = 0; i < 20; i++) {
		fscanf(fp, "%d", &data[i]);
	}

	for (int i = 0; i < 20; i++) {
		if (max < data[i]) {
			max = data[i];
			index = i;
		}
	}	
	
	fp = fopen("dataOut.txt", "w");
	fprintf(fp, "Max °ª: %d\n", max);
	fclose(fp);

	
	printf("max°ª: %d\nindex °ª: %d\n", max,index);
	fclose(fp);




}