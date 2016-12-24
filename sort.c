#include <stdbool.h>
#include <stdlib.h>
#include "util.h"
#include "sort.h"

#define CUTOFF 3

/**
 * Insertion Sort
 * [ Time   ] Avg: O(N^2) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] Yes
 */
void InsertionSort(int A[], int N) {
    for (int P = 1; P < N; P++) {
        int tmp = A[P];
        int j = P;
        while (j > 0 && A[j-1] > tmp) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = tmp;
    }
}

/**
 * Bubble Sort
 * [ Time   ] Avg: O(N^2) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] Yes
 */
void BubbleSort(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (A[j] > A[j+1]) {
                Swap(&A[j], &A[j+1]);
            }
        }
    }
}

/**
 * Optimized Bubble Sort
 * [ Time   ] Avg: O(N^2) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] Yes
 */
void OptimizedBubbleSort(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        bool swapped = false;
        for (int j = 0; j < N-i-1; j++) {
            if (A[j] > A[j+1]) {
                Swap(&A[j], &A[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

/**
 * Selection Sort
 * [ Time   ] Avg: O(N^2) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] No
 */
void SelectionSort(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        int min = i;
        for (int j = i+1; j < N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(&A[min], &A[i]);
        }
    }
}

/**
 * Shell Sort
 * [ Time   ] Avg: O(NLogN^2) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] No
 */
void ShellSort(int A[], int N) {
    for (int gap = N >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < N; i++) {
            int tmp = A[i];
            int j = i;
            while (j >= gap && A[j-gap] > tmp) {
                A[j] = A[j-gap];
                j -= gap;
            }
            A[j] = tmp;
        }
    }
}

/**
 * Heap Sort
 * [ Time   ] Avg: O(NLogN) Worst: O(NLogN)
 * [ Space  ] O(N)
 * [ Stable ] No
 */
void HeapSort(int A[], int N) {
    BuildHeap(A, N);

    for (int i = N-1; i > 0; --i) {
        Swap(&A[0], &A[i]);
        SiftDown(A, 0, i);
    }
}

static void BuildHeap(int A[], int N) {
    for (int i = N >> 1; i >= 0; --i) {
        SiftDown(A, i, N);
    }
}

static void SiftDown(int A[], int i, int N) {
    int tmp = A[i];
    for (int child = 2*i+1; child < N; child = 2*i+1) {
        if (child < N-1 && A[child+1] > A[child]) {
            child++;
        }
        if (A[child] > tmp) {
            A[i] = A[child];
            i = child;
        } else {
            break;
        }
    }
    A[i] = tmp;
}

/**
 * Merge Sort
 * [ Time   ] Avg: O(NLogN) Worst: O(NLogN)
 * [ Space  ] O(N)
 * [ Stable ] No
 */
void MergeSort(int A[], int N) {
    int *TmpArray = malloc(N * sizeof(A[0]));
    MSort(A, TmpArray, 0, N-1);
    free(TmpArray);
}

static void MSort(int A[], int TmpArray[], int left, int right) {
    if (left < right) {
        int mid = (right + left) >> 1;
        MSort(A, TmpArray, left, mid);
        MSort(A, TmpArray, mid+1, right);
        Merge(A, TmpArray, left, mid+1, right);
    }
}

static void Merge(int A[], int TmpArray[], int lpos, int rpos, int rend) {
    int lend = rpos - 1;
    int tpos = lpos;
    int length = rend - lpos + 1;
    
    while (lpos <= lend && rpos <= rend) {
        if (A[lpos] <= A[rpos]) {
            TmpArray[tpos++] = A[lpos++];
        } else {
            TmpArray[tpos++] = A[rpos++];
        }
    }

    while (lpos <= lend) {
        TmpArray[tpos++] = A[lpos++];
    }

    while (rpos <= rend) {
        TmpArray[tpos++] = A[rpos++];
    }

    for (int i = 0; i < length; i++, rend--) {
        A[rend] = TmpArray[rend];
    }
}

/**
 * Quick Sort
 * [ Time   ] Avg: O(NLogN) Worst: O(N^2)
 * [ Space  ] O(1)
 * [ Stable ] No
 */
void QuickSort(int A[], int N) {
    QSort(A, 0, N-1);
}

static void QSort(int A[], int left, int right) {
    if (left + CUTOFF < right) {
        int pivot = Median3(A, left, right);
        int i = left;
        int j = right - 1;

        while (true) {
            while (A[++i] < pivot) {}
            while (A[--j] > pivot) {}
            if (i < j) {
                Swap(&A[i], &A[j]);
            } else {
                break;
            }
        }
        Swap(&A[i], &A[right-1]);
        QSort(A, left, i-1);
        QSort(A, i+1, right);
    }
    else {
        InsertionSort(A + left, right - left + 1);
    }
}

static int Median3(int A[], int left, int right) {
    int median = (left + right) >> 1;
    if (A[left] > A[median]) Swap(&A[left], &A[median]);
    if (A[left] > A[right]) Swap(&A[left], &A[right]);
    if (A[median] > A[right]) Swap(&A[median], &A[right]);
    
    // hide pivot
    Swap(&A[median], &A[right-1]);
    return A[right-1];
}
