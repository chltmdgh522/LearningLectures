#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

// 큐에 데이터 삽입
void enqueue(int data, int position) {
    // 큐가 꽉 찬 경우
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("Full QUEUE.\n");
        return;
    }
    // 원하는 위치에 삽입하는 경우
    else if ((front != -1 && position > rear) || (front == -1 && position != 0)) {
        return;
    }
    // 큐가 비어있는 경우
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = data;
    }
    // 일반적인 경우
    else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        if (position == 0) {  // 큐의 맨 앞에 삽입하는 경우
            front = rear;
            queue[front] = data;
        }
        else {
            int i;
            for (i = rear; i > position; i = (i - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE) {
                queue[i] = queue[(i - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE];
            }
            queue[i] = data;
        }
    }
}

// 큐에서 데이터 삭제
int dequeue() {
    // 큐가 비어있는 경우
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    // 큐에 데이터가 하나만 있는 경우
    else if (front == rear) {
        int data = queue[front];
        front = rear = -1;
        return data;
    }
    // 일반적인 경우
    else {
        int data = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        return data;
    }
}

// 큐의 모든 데이터 출력
void printQueue() {
    printf("Queue: ");
    if (front != -1) {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d", queue[rear]);
    }
    printf("\n");
}

int main(void) {
    enqueue(1, 0);  // 큐의 맨 앞에 삽입
    printQueue();   // Queue: 1요소 0위치

    enqueue(2, 1);  // 2번째 위치에 삽입
    printQueue();   // Queue: 1요소 2위치

    enqueue(3, 0);  // 큐의 맨 앞에 삽입
    printQueue();   // Queue: 3 1 2

    dequeue();      // 데이터 삭제
    printQueue();   // Queue: 1 2

    return 0;
}