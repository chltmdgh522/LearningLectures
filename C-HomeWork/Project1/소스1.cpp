/*#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define WORD_LENGTH 20

int main(void) {
    char data[MAX_WORDS][WORD_LENGTH]; // �ڹٴ� �׳� �񱳰����ѵ� c���� �׳� ���ؼ� 2�����迭�� ���ҷ��� ������ �����߽��ϴ�.

    printf("10���� �ܾ��Է��ϼ���:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        scanf("%s", data[i]);
    }

    printf("\n10���� �Է¹��� �ܾ� ���:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%d: %s\n", i + 1, data[i]);
    }

    char search_word[WORD_LENGTH];
    int index;
    while (1) {
        printf("\nã�� ���� �ܾ��Է��ϼ��� ������ٸ� 0�� �Է��ϼ���\n");
        scanf("%s", search_word);

        if (strcmp(search_word, "0") == 0) { 
            break;
        }

        index = -1; 
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(search_word, data[i]) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) { 
            printf("No exist!!!\n");
        }
        else { 
            printf("%s �� %d ��°�� �ֽ��ϴ�.\n", search_word, index + 1);
        }
    }

    
}*/