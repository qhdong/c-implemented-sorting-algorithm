#include <stdio.h>

void PrintArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i % 10 == 0) printf("\n");
        printf("%4d", A[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void VerifyOrder(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        if (A[i] > A[i+1]) {
            printf("Error! Array[%d] > Array[%d]\n", i, i+1);
            return;
        }
    }
    printf("Sorted OK!\n");
}
