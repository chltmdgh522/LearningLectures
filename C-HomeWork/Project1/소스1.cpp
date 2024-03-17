/*#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define WORD_LENGTH 20

int main(void) {
    char data[MAX_WORDS][WORD_LENGTH]; // 자바는 그냥 비교가능한데 c언어는 그냥 못해서 2차원배열로 비교할려고 저렇게 저장했습니다.

    printf("10개의 단어입력하세용:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        scanf("%s", data[i]);
    }

    printf("\n10개의 입력받은 단어 출력:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%d: %s\n", i + 1, data[i]);
    }

    char search_word[WORD_LENGTH];
    int index;
    while (1) {
        printf("\n찾고 싶은 단어입력하세용 만약없다면 0을 입력하세용\n");
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
            printf("%s 는 %d 번째에 있습니다.\n", search_word, index + 1);
        }
    }

    
}*/