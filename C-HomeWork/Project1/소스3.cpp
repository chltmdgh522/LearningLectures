#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void) {
	FILE* fp;
	char data[20][30];
	fp = fopen("data.txt", "r");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			fscnaf(fp, "%c", data[i][j]);
		}
	}

	printf("%c",data[1][2]);

	fclose(fp);
}