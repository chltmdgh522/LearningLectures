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

char CACHE[CACHESIZE][CACHELINE];
int LRU[CACHESIZE] = { 0 };
int ex[CACHESIZE] = { 0 };

int totalLoads = 0;
int totalStores = 0;
int loadHits = 0;
int loadMisses = 0;
int storeHits = 0;
int storeMisses = 0;
int totalCycles = 0;

void cache(int oper, char* ad, int a) {
    printf("%d, %s\n", oper, ad);
    int exFlag = 0, temp = 0, cacheFlag = 0;
    for (temp = 0; temp < CACHESIZE; temp++) LRU[temp]++;
    temp = 0;
    while (temp < CACHESIZE) {
        if (strcmp(CACHE[temp], ad) == 0) { 
            cacheFlag = 1;
            printf("hit %d %s\n", oper, CACHE[temp]);
            LRU[temp] = 1; 
            exFlag = 1;   
            break;
        }
        temp++;
    }
    if (exFlag == 0) { 
        printf("miss %d %s\n", oper, ad);
        temp = 0;
        while (temp < CACHESIZE) {
            if (ex[temp] == 0) { 
                cacheFlag = 1;  
                for (int k = 0; k < CACHELINE; k++) {
                    CACHE[temp][k] = ad[k];
                }
                ex[temp] = 1;
                printf("%s, %d\n", CACHE[temp], temp);
                break;
            }
            temp++;
        }
        if (cacheFlag == 0) { 
            int index = 0, maxLRU = LRU[0];
            for (temp = 1; temp < CACHESIZE; temp++) {
                if (LRU[temp] > maxLRU) {
                    index = temp;
                    maxLRU = LRU[temp];
                }
            }
            for (int p = 0; p < CACHELINE; p++) { 
                CACHE[index][p] = ad[p];
            }
            LRU[index] = 1;
            ex[index] = 1;
            printf("Replaced at index %d with %s\n", index, CACHE[index]);
        }
        if (oper == 108) { 
            loadMisses++;
            printf("%d\n", a);
        }
        if (oper == 115) { 
            storeMisses++;
            printf("%d\n", a);
        }
    }
    else { // exist > hit
        if (oper == 108) { 
            loadHits++;
        }
        if (oper == 115) {
            storeHits++;
        }
    }
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
    if (result) {
        strncpy(result, str + start, length);
        result[length] = '\0';
    }
    return result;
}

int main() {
    int temp = 0;
    FILE* traceFile = fopen("LruMemory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 1;
    }
    char buffer[50];
    int oper;
    while (!feof(traceFile)) {
        oper = fgetc(traceFile);
        if (oper == EOF) break;
        fgets(buffer, sizeof(buffer), traceFile);
        strtok(buffer, "\n");
        strtok(buffer, " ");
        char* cutStr = splitString(buffer, 3, strlen(buffer) - 3);
        if (cutStr != NULL) {
            if (oper == 108) { 
                totalLoads++;
            }
            if (oper == 115) { 
                totalStores++;
            }
            cache(oper, cutStr, temp);
            free(cutStr);
        }
        totalCycles++;
        temp++;
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
