#include <stdbool.h>
#include <stdlib.h>
#include "mysort.h"
#include "util.h"

/**
 * Selection Sort
 * O(N^2), Not Stable
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
            Swap(&A[i], &A[min]);
        }
    }
}

/**
 * Bubble Sort
 * O(N^2) Stable
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
 * O(N^2) Stable
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
 * Insertion Sort
 * O(N^2) Not Stable
 */
void InsertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int j = i;
        int tmp = A[i];
        while (j > 0 && A[j-1] > tmp) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = tmp;
    }
}

/**
 * Shell Sort
 * O(NlogN) Not Stable
 */
// void ShellSort(int A[], int N) {
//    for (int gap = N >> 1; gap > 0; gap >>= 1) {


/**
 * Heap Sort
 * O(NlogN) Space: O(1) Not Stable
 */
void HeapSort(int A[], int N) {
    BuildHeap(A, N);

    for (int i = N-1; i > 0; i--) {
        Swap(&A[0], &A[i]);
        SiftDown(A, 0, i);
    }
}

static void BuildHeap(int A[], int N) {
    for (int i = N >> 1; i >= 0; i--) {
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
 * O(NlogN), Space: O(N), Stable
 */
void MergeSort(int A[], int N) {
    int *Tmp = malloc(N * sizeof(A[0]));
    MSort(A, Tmp, 0, N-1);
    free(Tmp);
}

static void MSort(int A[], int Tmp[], int left, int right) {
    if (left < right) {
        int middle = (left + right) >> 1;
        MSort(A, Tmp, left, middle);
        MSort(A, Tmp, middle+1, right);
        Merge(A, Tmp, left, middle+1, right);
    }
}

static void Merge(int A[], int Tmp[], int lpos, int rpos, int rend) {
    int lend = rpos - 1;
    int pos = lpos;
    int length = rend - lpos + 1;
    while (lpos <= lend && rpos <= rend) {
        if (A[lpos] < A[rpos]) {
            Tmp[pos++] = A[lpos++];
        } else {
            Tmp[pos++] = A[rpos++];
        }
    }
    while (lpos <= lend) Tmp[pos++] = A[lpos++];
    while (rpos <= rend) Tmp[pos++] = A[rpos++];
    for (int i = 0; i < length; i++, rend--) {
        A[rend] = Tmp[rend];
    }
}

/**
 * Quick Sort
 * O(NlogN), O(N^2), Not Stable
 */
void QuickSort(int A[], int N) {
    QSort(A, 0, N-1);
}

static void QSort(int A[], int left, int right) {
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

static int Median3(int A[], int left, int right) {
    int middle = (left + right) >> 1;
    if (A[left] > A[middle]) Swap(&A[left], &A[middle]);
    if (A[left] > A[right]) Swap(&A[left], &A[right]);
    if (A[middle] > A[right]) Swap(&A[middle], &A[right]);

    Swap(&A[middle], &A[right-1]);
    return A[right-1];
}
