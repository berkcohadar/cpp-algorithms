#include <stdio.h>
#include <stdlib.h>
#include "search.hh"
#include <bits/stdc++.h> 
using namespace std; 

int binary_opearations;

int Search(int arr[], int left, int right, int x) 
{ 
    if (right >= left) { 
        binary_opearations++;
        int mid = left + (right - left) / 2; 

        if (arr[mid] == x) return binary_opearations; 
  
        if (arr[mid] > x) return Search(arr, left, mid - 1, x); 
        
        return Search(arr, mid + 1, right, x); 
    }
    binary_opearations++;
    return binary_opearations;
}

int binarySearch(int arr[], int left, int right, int x){
    binary_opearations=0;
    return Search(arr,left,right,x);
}

int linear_search(int arr[], int size, int x){
    int linear_operations = 0;
    for(int i=0; i<size; i++){
        linear_operations++;
        if(arr[i] == x) return linear_operations;
    }
    return linear_operations;
}

int jumpSearch(int arr[], int size, int x) 
{ 
    int next = sqrt(size); 
    int prev = 0;
    int operations = 0;
    while (arr[min(next, size)-1] < x) 
    { 
        operations++;
        prev = next; 
        next += sqrt(size); 
        if (prev >= size) return operations; 
    } 
    while (arr[prev] < x) 
    { 
        operations++; prev++; 
        if (prev == min(next, size)) return operations++;; 
    }
    operations++;
    if (arr[prev] == x) return operations; 
  
    return operations; 
}
