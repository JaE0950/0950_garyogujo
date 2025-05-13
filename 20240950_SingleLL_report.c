/*#include <stdio.h>//실습 1-4
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 맨 앞에 노드 삽입
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 리스트 출력 함수
void printList(Node* head) {
    Node* current = head;
    printf("현재 리스트: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 테스트용 main 함수
int main() {
    Node* head = NULL;

    // 노드 삽입
    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);

    // 리스트 출력 (함수 호출)
    printList(head);

    return 0;
}*/
/*#include <stdio.h>//실습 1-5 함수 1
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 맨 앞에 삽입하는 함수
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 리스트 출력 함수
void printList(Node* head) {
    Node* current = head;
    printf("현재 리스트: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// searchValue1 함수: 값의 위치를 반환 (0부터 시작), 없으면 -1 반환
int searchValue1(Node* head, int val) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == val) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // 못 찾은 경우
}

// 테스트용 main 함수
int main() {
    Node* head = NULL;
    int pos = -1;
    int val = 30;

    // 노드 삽입
    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    head = insertFirst(head, 40);

    // 리스트 출력
    printList(head);

    // 값 탐색
    pos = searchValue1(head, val);
    if (pos != -1)
        printf("%d의 위치는 %d번째입니다.\n", val, pos);
    else
        printf("%d는 리스트에 존재하지 않습니다.\n", val);

    return 0;
}*/
/*#include <stdio.h>//예제제1-5 함수 2
#include <stdlib.h>

// 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 맨 앞에 삽입
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 리스트 출력
void printList(Node* head) {
    Node* current = head;
    printf("현재 리스트: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 특정 값을 찾아 앞/뒤 노드의 값을 출력
void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            printf("%d를 찾았습니다.\n", val);

            if (prev != NULL)
                printf("앞 노드 값: %d\n", prev->data);
            else
                printf("앞 노드 없음\n");

            if (current->next != NULL)
                printf("뒤 노드 값: %d\n", current->next->data);
            else
                printf("뒤 노드 없음\n");

            return;
        }

        prev = current;
        current = current->next;
    }

    printf("%d는 리스트에 존재하지 않습니다.\n", val);
}

// 테스트용 main
int main() {
    Node* head = NULL;
    int val = 30;

    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    head = insertFirst(head, 40);

    printList(head);

    searchValue2(head, val);

    return 0;
}*/
/*#include <stdio.h>//실습1-5 함수3
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 맨 앞에 삽입
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 리스트 출력
void printList(Node* head) {
    Node* current = head;
    printf("현재 리스트: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 특정 값 위치 찾기
int searchValue1(Node* head, int val) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == val) return index;
        current = current->next;
        index++;
    }
    return -1;
}

// 앞/뒤 노드 정보 출력
void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            printf("%d를 찾았습니다.\n", val);

            if (prev != NULL)
                printf("앞 노드 값: %d\n", prev->data);
            else
                printf("앞 노드 없음\n");

            if (current->next != NULL)
                printf("뒤 노드 값: %d\n", current->next->data);
            else
                printf("뒤 노드 없음\n");

            return;
        }
        prev = current;
        current = current->next;
    }

    printf("%d는 리스트에 존재하지 않습니다.\n", val);
}

// 리스트 메모리 해제
void freeList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        printf("노드 %d 메모리 해제\n", temp->data); // 확인용 출력
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int val = 30;
    int pos = -1;

    // 노드 삽입
    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    head = insertFirst(head, 40);

    // 리스트 출력
    printList(head);

    // 값 위치 찾기
    pos = searchValue1(head, val);
    if (pos != -1)
        printf("%d의 위치는 %d번째입니다.\n", val, pos);
    else
        printf("%d는 리스트에 존재하지 않습니다.\n", val);

    // 앞/뒤 노드 출력
    searchValue2(head, val);

    // 리스트 메모리 해제
    freeList(head);

    return 0;
}*/



