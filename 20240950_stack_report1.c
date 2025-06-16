#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *data;   
    int top;       
    int capacity; 
} Stack;


void initStack(Stack *s, int initialSize) {
    s->data = (char *)malloc(initialSize * sizeof(char));
    if (s->data == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialSize;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}


void expandStack(Stack *s) {
    int newCapacity = s->capacity + 10;
    char *newData = (char *)realloc(s->data, newCapacity * sizeof(char));
    if (newData == NULL) {
        printf("메모리 재할당 실패!\n");
        exit(1);
    }
    s->data = newData;
    s->capacity = newCapacity;
}


void push(Stack *s, char ch) {
    if (isFull(s)) {
        expandStack(s);
    }
    s->data[++(s->top)] = ch;
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택 언더플로우! 제거할 문자가 없습니다.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}


void freeStack(Stack *s) {
    free(s->data);
}


int main() {
    Stack s;
    initStack(&s, 10);  

    char str[101];  
    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    printf("거꾸로 출력된 문자열: ");
    while (!isEmpty(&s)) {
        putchar(pop(&s));
    }
    printf("\n");

    freeStack(&s);
    return 0;
}
