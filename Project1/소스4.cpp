#include <stdio.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 30

void bubbleSort(char arr[][MAX_WORD_LENGTH], int n) {
    int i, j;
    char temp[MAX_WORD_LENGTH];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    char data[MAX_WORDS][MAX_WORD_LENGTH];
    FILE* fp_in, * fp_out;
    int i;

    fp_in = fopen("data.txt", "r");
    if (fp_in == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return -1;
    }
    for (i = 0; i < MAX_WORDS; i++) {
        if (fgets(data[i], MAX_WORD_LENGTH, fp_in) == NULL) {
            break;
        }
    }
    fclose(fp_in);

    bubbleSort(data, i);

    for (int j = 0; j < i; j++) {
        printf("%s", data[j]);
    }

    fp_out = fopen("dataOut.txt", "w");
    if (fp_out == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return -1;
    }
    for (int j = 0; j < i; j++) {
        fprintf(fp_out, "%s", data[j]);
    }
    fclose(fp_out);

    return 0;
}