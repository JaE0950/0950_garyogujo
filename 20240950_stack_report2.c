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


void freeStack(Stack *s) {
    free(s->data);
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}


void expandStack(Stack *s) {
    s->capacity += 10;
    char *newData = realloc(s->data, s->capacity * sizeof(char));
    if (newData == NULL) {
        printf("메모리 재할당 실패!\n");
        exit(1);
    }
    s->data = newData;
}

void push(Stack *s, char ch) {
    if (isFull(s)) {
        expandStack(s);
    }
    s->data[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidParentheses(const char *str) {
    Stack s;
    initStack(&s, 10);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                freeStack(&s);
                return 0; 
            }
        }
    }

    int valid = isEmpty(&s);  
    freeStack(&s);
    return valid;
}


int main() {
    char input[201];
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

 
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (isValidParentheses(input)) {
        printf("유효한 괄호\n");
    } else {
        printf("유효하지 않은 괄호\n");
    }

    return 0;
}
