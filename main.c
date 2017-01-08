#include <stdio.h>
#include "sort.h"
#include "util.h"

int main() {
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int N = sizeof(A) / sizeof(A[0]);
    PrintArray(A, N);
    // InsertionSort(A, N);
    // BubbleSort(A, N);
    // OptimizedBubbleSort(A, N);
    // SelectionSort(A, N);
    // ShellSort(A, N);
    HeapSort(A, N);
    // MergeSort(A, N);
    // QuickSort(A, N);
    PrintArray(A, N);
    VerifyOrder(A, N);

    return 0;
}
