#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include "sorts.hh"
#include "search.hh"
#include "now.hh"

#include <fstream>
#include <string>
#include <vector>

#include <cstring>



void print_list(int a[], int length){
    int i;
    for (i=0;i<length;i++) printf("%d ", a[i]);
    printf("\n");
}

void print_to_file(FILE* f, long diff,int swaps){
    char str[256]; sprintf(str, "%ld", diff);
    char str2[256]; sprintf(str2, "%d", swaps);
    fprintf(f,"%s\t\t\t%s\n",str,str2);
}

void print_to_file_search(FILE* f, long diff,int ops, char* found){
    char str[256]; sprintf(str, "%ld", diff);
    char str2[256]; sprintf(str2, "%d", ops);
    fprintf(f,"%s\t\t\t%s\t\t\t%s\n",str,str2,found);
}


using namespace std;
int main(){
    FILE *fa = fopen("solutions.txt", "w");
    fprintf(fa,"\t\t\t\t\t\tARRAY SIZE: 10.000\n\n");
    fprintf(fa,"ALGORITHM\t\t\tDATA\t\t\tORDER\t\t\tTIME\t\t\tSWAPS\n");
    fprintf(fa,"-----------------------------------------------------------------------------------------------------------------\n");

    long avg_quick=0,avg_insert=0,avg_bubble=0,avg_merge=0,avg_select=0,avg_heap=0;

    int size = 10000;
    int array[size];
    /* --------------------- SORTING --------------------- */
    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"QuickSort\t\t\tINT\t\t\tRandom\t\t\t");
    long time0 = now();
    int swaps = quickSort(array,size);
    long time1 = now();
    avg_quick+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"Insertion\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    swaps = insertionSort(array,size);
    time1 = now();
    avg_insert+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"BubbleSort\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    swaps = bubbleSort(array,size);
    time1 = now();
    avg_bubble+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
    
    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"Selection\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    swaps = selectionSort(array,size);
    time1 = now();
    avg_select+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
    
    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"MergeSort\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    swaps = mergeSort(array,size);
    time1 = now();
    avg_merge+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    srand((unsigned)time(0));
    for(int i=0; i<size; i++) array[i] = (rand()%10000)+1;
    fprintf(fa,"HeapSort\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    swaps = heapSort(array,size);
    time1 = now();
    avg_heap+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    for(int i=0; i<size; i++) array[i] = i+1; 
    fprintf(fa,"QuickSort\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = quickSort(array,size);
    time1 = now();
    avg_quick+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
     
    for(int i=0; i<size; i++) array[i] = i+1;
    fprintf(fa,"Insertion\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = insertionSort(array,size);
    time1 = now();
    avg_insert+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
     
    for(int i=0; i<size; i++) array[i] = i+1;
    fprintf(fa,"BubbleSort\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = bubbleSort(array,size);
    time1 = now();
    avg_bubble+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
     
    for(int i=0; i<size; i++) array[i] = i+1;
    fprintf(fa,"Selection\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = selectionSort(array,size);
    time1 = now();
    avg_select+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
     
    for(int i=0; i<size; i++) array[i] = i+1;
    fprintf(fa,"MergeSort\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = mergeSort(array,size);
    time1 = now();
    avg_merge+=time1-time0;
    print_to_file(fa, time1-time0,swaps);


    for(int i=0; i<size; i++) array[i] = i+1;
    fprintf(fa,"HeapSort\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    swaps = heapSort(array,size);
    time1 = now();
    avg_heap+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    int j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"QuickSort\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = quickSort(array,size);
    time1 = now();
    avg_quick+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"Insertion\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = insertionSort(array,size);
    time1 = now();
    avg_insert+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"BubbleSort\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = bubbleSort(array,size);
    time1 = now();
    avg_bubble+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
    
    j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"Selection\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = selectionSort(array,size);
    time1 = now();
    avg_select+=time1-time0;
    print_to_file(fa, time1-time0,swaps);
    
    j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"MergeSort\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = mergeSort(array,size);
    time1 = now();
    avg_merge+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    j = 0;
    for(int i=size; i>0; i--){ array[j] = i; j++;}
    fprintf(fa,"HeapSort\t\t\tINT\t\t\tReverse\t\t\t");
    time0 = now();
    swaps = heapSort(array,size);
    time1 = now();
    avg_heap+=time1-time0;
    print_to_file(fa, time1-time0,swaps);

    fprintf(fa,"\n\n**SWAPS REPRESENTS COMPARES FOR MERGE SORT**\n\n");

    /* --------------------- SEARCHING --------------------- */
    fprintf(fa,"\n\n\n\t\t\t\t\t\tARRAY SIZE: 1.000.000\n\n");
    fprintf(fa,"ALGORITHM\t\t\tDATA\t\t\tORDER\t\t\tTIME\t\t\tOPS\t\t\tFOUND\n");
    fprintf(fa,"-----------------------------------------------------------------------------------------------------------------------------------------\n");

    char* found;
    char t[16] = "TRUE";
    char f[16] = "FALSE";
    size = 1000000;
    int array2[size];
    
    srand((unsigned)time(0)); 
    for(int i=0; i<size; i++) array2[i] = (rand()%1000000)+1;
    fprintf(fa,"Linear\t\t\t\tINT\t\t\tRandom\t\t\t");
    time0 = now();
    int operations = linear_search(array2,size,(rand()%1000000)+1);
    time1 = now();
    if(operations == size) found = f;
    else found = t;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Binary\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = binarySearch(array2,0,size-1,865146);
    time1 = now();
    found = t;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Binary\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = binarySearch(array2,0,size-1,-1);
    time1 = now();
    found = f;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Jump\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = jumpSearch(array2,size,865146);
    time1 = now();
    found = t;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Jump\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = jumpSearch(array2,size,1000000);
    time1 = now();
    found = t;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Jump\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = jumpSearch(array2,size,-1);
    time1 = now();
    found = f;
    print_to_file_search(fa, time1-time0,operations,found);

    for(int i=0; i<size; i++) array2[i] = i+1;
    fprintf(fa,"Jump\t\t\t\tINT\t\t\tSorted\t\t\t");
    time0 = now();
    operations = jumpSearch(array2,size,1000001);
    time1 = now();
    found = f;
    print_to_file_search(fa, time1-time0,operations,found);

    /* --------------------- AVERAGE --------------------- */
    fprintf(fa,"\n\n\nAVERAGE TIME SPENT IN SORTING ALGORTIHMS WITH 10.000 ELEMENTS\n");
    fprintf(fa,"-------------------------------------------------------------------------------------------------\n");

    fprintf(fa,"Quick Sort     :    %ld ms\n",avg_quick/3);
    fprintf(fa,"Merge Sort     :    %ld ms\n",avg_merge/3);
    fprintf(fa,"Heap Sort      :    %ld ms\n",avg_heap/3);
    fprintf(fa,"Selection Sort :    %ld ms\n",avg_select/3);
    fprintf(fa,"Insertion Sort :    %ld ms\n",avg_insert/3);
    fprintf(fa,"Bubble Sort    :    %ld ms\n",avg_bubble/3);

    fclose(fa);
}