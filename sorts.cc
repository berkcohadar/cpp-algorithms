#include <stdio.h>
#include <stdlib.h>
#include "sorts.hh"

static void swap(int a[], int i, int j){
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int insertionSort(int a[], int n) {
    int swap_counter = 0;
    for (int i = 1; i < n; ++i) for (int j = i; (j > 0) && (a[j] < a[j - 1]); --j) { 
        swap(a, j, j - 1);
        swap_counter++;
    }
    return swap_counter;
}

int bubbleSort(int a[], int n) {
    int swap_counter = 0;
    for (int i = 0; i < n - 1; ++i)  for (int j = n - 1; j > i; --j)  if (a[j] < a[j - 1]) {
        swap(a, j, j - 1);
        swap_counter++;
    }
    return swap_counter;
}

int selectionSort(int a[], int n){
  int swap_counter = 0;
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = n - 1; j > i; --j) if (a[j] < a[minIndex]) minIndex = j;
    swap(a, i, minIndex);
    swap_counter++;
  }
  return swap_counter;
}

static void msort(int a[], int temp[], int lo, int hi) {
  if (hi - lo < 2) return;
  int mid = (lo + hi)/2;   
  msort(a, temp, lo, mid); 
  msort(a, temp, mid, hi); 
  
  for (int i = lo; i < hi; ++i) temp[i] = a[i];

  int i1 = lo;
  int i2 = mid;
  for (int dest = lo; dest < hi; ++dest) {
    if (i1 == mid) a[dest] = temp[i2++];
    else if (i2 == hi) a[dest] = temp[i1++];
    else if (temp[i1] <= temp[i2]) a[dest] = temp[i1++];
    else  a[dest] = temp[i2++];
  }
}

void mergeSort(int a[], int n) {
  int* temp = new int[n];
  msort(a, temp, 0, n);
  delete temp;
}

static int findPivot(int a[], int i, int j) { return (i+j)/2; }

int quick_swap;

static int partition(int a[], int lo, int hi, int pivot){
  while (lo <= hi) {
    while (a[lo] < pivot) ++lo;
    while ((hi >= lo) && (a[hi] >= pivot)) --hi;
    if (hi > lo) { swap(a, lo, hi); quick_swap++;}
  }
  return lo;
}


static void qsort(int a[], int lo, int hi)
{
  if (hi - lo < 1) return;
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  quick_swap++;
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  quick_swap++;
  qsort(a, lo, k - 1);
  qsort(a, k + 1, hi);
}

int quickSort(int a[], int n) {
    quick_swap = 0;
    qsort(a, 0, n - 1);
    return quick_swap;
}

int heap_swap;
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(arr, i, largest);
        heap_swap++;
        heapify(arr, n, largest); 
    } 
} 
  
int heapSort(int arr[], int n) 
{
    heap_swap = 0;
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    for (int i=n-1; i>0; i--) 
    { 
        swap(arr, 0, i); 
        heap_swap++;
        heapify(arr, i, 0); 
    }
    return heap_swap;
} 