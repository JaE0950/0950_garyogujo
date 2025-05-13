#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 연락처 노드 정의
typedef struct Contact {
    char name[30];
    char phone[20];
    struct Contact* next;
} Contact;

// 연락처 추가 (리스트 맨 앞에 삽입)
Contact* addContact(Contact* head, const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = head;
    return newContact;
}

// 연락처 검색
void searchContact(Contact* head, const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("'%s' 연락처를 찾을 수 없습니다.\n", name);
}

// 연락처 삭제
Contact* deleteContact(Contact* head, const char* name) {
    Contact* current = head;
    Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            printf("'%s' 연락처가 삭제되었습니다.\n", name);
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("'%s' 연락처가 존재하지 않습니다.\n", name);
    return head;
}

// 전체 연락처 출력
void printContacts(Contact* head) {
    if (head == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }

    printf("전화번호부:\n");
    Contact* current = head;
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// 메모리 해제
void freeContacts(Contact* head) {
    Contact* current = head;
    while (current != NULL) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Contact* phonebook = NULL;

    // 연락처 추가
    phonebook = addContact(phonebook, "홍길동", "010-1234-5678");
    phonebook = addContact(phonebook, "김철수", "010-9876-5432");
    phonebook = addContact(phonebook, "이영희", "010-1111-2222");

    // 전화번호부 출력
    printContacts(phonebook);
    printf("\n");

    // 연락처 검색
    searchContact(phonebook, "김철수");
    searchContact(phonebook, "박지성"); // 없는 이름

    printf("\n");

    // 연락처 삭제
    phonebook = deleteContact(phonebook, "홍길동");
    phonebook = deleteContact(phonebook, "박지성"); // 없는 이름

    printf("\n");

    // 최종 출력
    printContacts(phonebook);

    // 메모리 해제
    freeContacts(phonebook);

    return 0;
}
