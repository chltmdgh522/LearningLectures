#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이진 검색 함수
int binarySearch(int arr[], int low, int high, int key) {
    if (high < low) {
        return -1; // 검색 실패
    }

    int mid = (low + high) / 2;
    if (key == arr[mid]) {
        return mid; // 검색 성공
    }
    else if (key < arr[mid]) {
        return binarySearch(arr, low, mid - 1, key); // 왼쪽 부분 배열 검색
    }
    else {
        return binarySearch(arr, mid + 1, high, key); // 오른쪽 부분 배열 검색
    }
}

int main() {
    // 파일 열기
    FILE* fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File open error!\n");
        return 1;
    }

    // 파일에서 정수 읽어오기
    int arr[20];
    int i = 0;
    while (fscanf(fp, "%d", &arr[i]) != EOF) {
        i++;
    }
    fclose(fp);

    // 배열 정렬하기
    for (int i = 0; i < 19; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // 정렬된 배열 출력하기
    printf("Sorted Array:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d\n", arr[i]);
    }

    // 검색할 단어 입력받기
    int key;
    printf("Enter a number to search: ");
    scanf("%d", &key);

    // 이진 검색으로 검색하기
    int result = binarySearch(arr, 0, 19, key);
    if (result == -1) {
        printf("No Exist!!!\n"); // 검색 실패
    }
    else {
        printf("Index of %d is %d.\n", key, result + 1); // 검색 성공
    }

    return 0;
}
