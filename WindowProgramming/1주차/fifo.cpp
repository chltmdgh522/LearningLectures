#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
        
#define MEMSIZE 128
#define BLOCKSIZE 4
#define LINESIZE 4
#define MEMBLSIZE 32
#define CACHESIZE 32
#define CACHELINE 8

char CACHE[CACHESIZE][8];
int FIFO_queue[CACHESIZE];
int ex[CACHESIZE] = { 0 };
int queue_front = 0;
int queue_rear = -1;
int totalLoads = 0;
int totalStores = 0;
int loadHits = 0;
int loadMisses = 0;
int storeHits = 0;
int storeMisses = 0;
int totalCycles = 0;

void enqueue(int index) {
    queue_rear = (queue_rear + 1) % CACHESIZE;
    FIFO_queue[queue_rear] = index;
}

int dequeue() {
    int index = FIFO_queue[queue_front];
    queue_front = (queue_front + 1) % CACHESIZE;
    return index;
}

void cache(int oper, char* ad, int a) {
    printf("%d,%s\n", oper, ad);
    int exFlag = 0, temp = 0;

    // ĳ ÿ   ּҰ   ִ    Ȯ  
    for (temp = 0; temp < CACHESIZE; temp++) {
        if (strcmp(CACHE[temp], ad) == 0) {            
            printf("hit %d %s\n", oper, CACHE[temp]);
            exFlag = 1;     //      flag 1       
            break;
        }
    }

    if (exFlag == 0) {
        printf("miss %d %s\n", oper, ad);

     
        for (temp = 0; temp < CACHESIZE; temp++) {
            if (ex[temp] == 0) { 
                strncpy(CACHE[temp], ad, 8);     
                ex[temp] = 1;
                enqueue(temp);  
                printf("%s,%d\n", CACHE[temp], temp);
                exFlag = 1;
                break;
            }
        }

        if (exFlag == 0) {                    
            int index = dequeue();              
            strncpy(CACHE[index], ad, 8);
            enqueue(index);  \
            printf("%d\n", index);
        }

        if (oper == 108) {  // oper == load
            loadMisses++;
        }
        else if (oper == 115) {  // oper == store
            storeMisses++;
        }
    }
    else {  // exist > hit
        if (oper == 108) {  // oper == load
            loadHits++;
        }
        else if (oper == 115) {  // oper == store
            storeHits++;
        }
    }

    totalCycles++;
}

char* splitString(char* str, int start, int length) {
    int strLength = strlen(str);
    if (start >= strLength || length <= 0) {
        return NULL;
    }
    int end = start + length;
    if (end > strLength) {
        end = strLength;
    }
    char* result = (char*)malloc(length + 1);
    strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}

int main() {
    int temp = 0;
    FILE* traceFile = fopen("FifoMemory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 0;
    }

    char buffer[50];
    int oper;
    while (!feof(traceFile)) {
        oper = fgetc(traceFile);
        fgets(buffer, sizeof(buffer), traceFile);
        strtok(buffer, "\n");
        strtok(buffer, " ");
        char* cutStr = splitString(buffer, 3, strlen(buffer) - 3);
        if (cutStr != NULL) {
            if (oper == 108) {  
                totalLoads++;
            }
            else if (oper == 115) {
                totalStores++;
            }
            cache(oper, cutStr, temp);
            free(cutStr);
        }
        temp++;
        printf("    count : %d\n", totalCycles);
    }

    printf("Total loads: %d\n", totalLoads);
    printf("Total stores: %d\n", totalStores);
    printf("Load hits: %d\n", loadHits);
    printf("Load misses: %d\n", loadMisses);
    printf("Store hits: %d\n", storeHits);
    printf("Store misses: %d\n", storeMisses);
    printf("Total cycles: %d\n", totalCycles);
    fclose(traceFile);

    return 0;
}
