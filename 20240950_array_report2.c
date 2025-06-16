#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);
void removeStudent(int scores[], int* size, int studentNumber);
void addStudent(int** scores, int* size, int newScore);

int main() {
    int initialSize = 30;
    int* scores = (int*)malloc(initialSize * sizeof(int));
    int size = initialSize;
    int studentNumber;
    double average;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, size);
    printf("학급 평균 점수: %.2f\n", average);
    printf("학생 번호를 입력하세요 (1 ~ %d): ", size);
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, size, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    } else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }

    printf("\n--- 평균 이상 학생 목록 (옵션 1) ---\n");
    printScore(scores, size, average, 1);

    printf("\n--- 평균 미만 학생 목록 (옵션 2) ---\n");
    printScore(scores, size, average, 2);

    printf("\n--- 전체 학생 목록 (옵션 0) ---\n");
    printScore(scores, size, average, 0);

    // 전학 처리
    printf("\n학생 10번이 전학을 갔습니다.\n");
    removeStudent(scores, &size, 10);

    printf("두 명의 새로운 학생이 전학을 왔습니다.\n");
    addStudent(&scores, &size, rand() % 101);
    addStudent(&scores, &size, rand() % 101);

    average = calculateAverage(scores, size);
    printf("\n[변경 후] 학급 평균 점수: %.2f\n", average);

    printf("\n--- 변경 후 전체 학생 목록 ---\n");
    printScore(scores, size, average, 0);

    free(scores);
    return 0;
}

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    } else {
        return -1;
    }
}

void printScore(int scores[], int size, double average, int option) {
    for (int i = 0; i < size; i++) {
        int studentNum = i + 1;
        int score = scores[i];

        if (option == 0 ||
            (option == 1 && score >= average) ||
            (option == 2 && score < average)) {
            printf("학생 %2d번: %3d점\n", studentNum, score);
        }
    }
}

void removeStudent(int scores[], int* size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > *size) {
        printf("유효하지 않은 학생 번호입니다.\n");
        return;
    }

    int index = studentNumber - 1;

    for (int i = index; i < *size - 1; i++) {
        scores[i] = scores[i + 1];
    }
    (*size)--;
}

void addStudent(int** scores, int* size, int newScore) {
    int newSize = *size + 1;
    int* newArray = (int*)realloc(*scores, newSize * sizeof(int));

    if (newArray == NULL) {
        printf("메모리 재할당 실패\n");
        return;
    }

    newArray[*size] = newScore;
    *scores = newArray;
    *size = newSize;
}
