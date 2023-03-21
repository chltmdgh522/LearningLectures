#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define STACK_SIZE 10
int main(void) {
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

	int* stack;
	int top = -1;               // top 초기화
	int size = 1;

	int isEmpty() {
		if (top == -1) return 1;
		else return 0;
	}

	int pop() {
		if (isEmpty()) {	// 스택이 공백 상태인 경우
			printf("\n\n Stack is Empty!!\n");
			return 0;
		}
		else
		{
			// 동적 배열로 구현
			int i, re, * temp;

			if (top % 10 == 0)
			{
				printf(" CHANGE STACK\n");
				re = stack[top];
				temp = (int*)malloc(STACK_SIZE * (size - 1) * sizeof(int));
				for (i = 0; i < top; i++) temp[i] = stack[i];

				free(stack);

				stack = (int*)malloc(STACK_SIZE * (size - 1) * sizeof(int));

				for (i = 0; i < top; i++) stack[i] = temp[i];

				free(temp);

				top--;
				size--;

				return re;

			}
			else
				return stack[top--];	      // 현재 top의 원소를 삭제한 후 top 감소
		}
	}

	// 스택이 포화 상태인지 확인하는 연산
	int isFull() {
		if (top % STACK_SIZE == 9) return 1;
		else return 0;
	}

	// 스택의 top에 원소를 삽입하는 연산
	void push(int item) {
		int* temp;

		if (isFull()) {
			printf(" Full STACK\n");
			temp = (int*)malloc((STACK_SIZE * size) * sizeof(int));

			for (int i = 0; i < (top + 1); i++) temp[i] = stack[i];

			free(stack);

			stack = (int*)malloc((STACK_SIZE * (size + 1)) * sizeof(int));

			for (int i = 0; i < (top + 1); i++) stack[i] = temp[i];
			stack[++top] = item;  // top을 증가시킨 후 현재 top에 원소 삽입

			size++;

			free(temp);

		}
		else stack[++top] = item;  // top을 증가시킨 후 현재 top에 원소 삽입
	}

	// 스택의 원소를 출력하는 연산
	void printStack() {
		int i;
		printf(" STACK SIZE [%d]\n", (STACK_SIZE * size));
		printf("\n STACK [ ");
		for (i = 0; i <= top; i++) printf("%d ", stack[i]);
		printf("]\n");
	}

	int main(void) {
		int i;
		stack = (int*)malloc(STACK_SIZE * sizeof(int));

		for (i = 0; i < 44; i++) push(i + 1);

		printStack();

		for (i = 0; i < 7; i++) printf(" POP Data [%d]\n", pop());

		printStack();

		free(stack);

		getchar();
	}
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