#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define NUM_STRUCTURES 20

// 데이터를 저장하는 구조체
typedef struct {
    int num;
    char name[MAX_NAME_LENGTH];
} Data;

// 이진 트리 노드 정의
typedef struct TreeNode {
    Data data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 이진 트리에 데이터 삽입
TreeNode* insert(TreeNode* root, Data data) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data.num < root->data.num)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// 이진 트리를 중위 순회하여 정렬된 결과 출력
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d %s\n", root->data.num, root->data.name);
        inorderTraversal(root->right);
    }
}

// 이진 검색을 수행하여 데이터를 찾고 해당 데이터의 인덱스 반환
int binarySearch(TreeNode* root, int key, int index) {
    if (root == NULL)
        return -1;  // 데이터를 찾지 못한 경우

    if (key == root->data.num)
        return index;  // 데이터를 찾은 경우

    if (key < root->data.num)
        return binarySearch(root->left, key, 2 * index);  // 왼쪽 서브트리 검색

    return binarySearch(root->right, key, 2 * index + 1);  // 오른쪽 서브트리 검색
}

int main() {
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 파일에 데이터 기록
    for (int i = 0; i < NUM_STRUCTURES; i++) {
        Data data;
        printf("Enter an integer: ");
        scanf("%d", &(data.num));
        printf("Enter a name: ");
        scanf("%s", data.name);

        fprintf(file, "%d %s\n", data.num, data.name);
    }

    fclose(file);

    // 파일에서 데이터 읽어와 구조체에 저장
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    TreeNode* root = NULL;

    for (int i = 0; i < NUM_STRUCTURES; i++) {
        Data data;
        fscanf(file, "%d %s", &(data.num), data.name);
        root = insert(root, data);
    }

    fclose(file);

    // 정렬된 결과 출력
    printf("Sorted data:\n");
    inorderTraversal(root);
}
