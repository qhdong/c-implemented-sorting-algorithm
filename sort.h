#ifndef _HEADER_SORT_H_
#define _HEADER_SORT_H_

void InsertionSort(int A[], int N);
void BubbleSort(int A[], int N);
void OptimizedBubbleSort(int A[], int N);
void SelectionSort(int A[], int N);
void ShellSort(int A[], int N);
void HeapSort(int A[], int N);
static void SiftDown(int A[], int i, int N);
static void BuildHeap(int A[], int N);
void MergeSort(int A[], int N);
static void MSort(int A[], int TmpArray[], int left, int end);
static void Merge(int A[], int TmpArray[], int lpos, int rpos, int rend);
void QuickSort(int A[], int N);
static void QSort(int A[], int left, int right);
static int Median3(int A[], int left, int right);

#endif
