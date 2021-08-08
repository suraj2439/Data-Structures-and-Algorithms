#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//--------------------------------------------------

void bubbleSort(int *arr, int N) {
    int flag = 1;
    for(int i = 0; i < N-1 && flag; i++) {
        flag = 0;
        for(int j = 0; j < N-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 1;
            }
        }
    }
}

//--------------------------------------------------

void selectionSort(int *arr, int N) {
    for(int i = 0; i < N-1; i++) {
        int min_indx = i;
        for(int j = i+1; j < N; j++) {
            if(arr[j] < arr[min_indx])
                min_indx = j;   
        }
        int tmp = arr[min_indx];
        arr[min_indx] = arr[i];
        arr[i] = tmp;
    }
}

//--------------------------------------------------

void insertionSort(int *arr, int N) {
    for(int i = 1; i < N; i++) {
        int j = i-1;
        int val = arr[i];
        while(j >= 0 && arr[j] > val) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

//--------------------------------------------------

void merge(int *arr, int left, int mid, int right) {
    int lcount = mid-left+1, rcount = right-mid;
    int Larr[lcount], Rarr[rcount];
    for(int i = 0; i < lcount; i++)
        Larr[i] = arr[i+left];
    for(int i = 0; i < rcount; i++)
        Rarr[i] = arr[i+mid+1];

    int i = 0, j = 0, k = left;
    while(i < lcount && j < rcount) {
        if(Larr[i] < Rarr[j]) 
            arr[k++] = Larr[i++];
        else arr[k++] = Rarr[j++];
    }

    while(i < lcount)
        arr[k++] = Larr[i++];
    while(j < rcount)
        arr[k++] = Rarr[j++];
}

void mergeSortUtil(int *arr, int left, int right) {
    if(left < right) {
        int mid = left+(right-left)/2;
        mergeSortUtil(arr, left, mid);
        mergeSortUtil(arr, mid+1, right);
        //printf("%d %d %d ll\n", left, mid, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int *arr, int N) {
    mergeSortUtil(arr, 0, N-1);
}

//--------------------------------------------------

void quickSortUtil(int *arr, int left, int right) {
    if(left > right) 
        return;

    int pivot = arr[left];
    int i = left+1, j = right;
    while(i <= j) {
        if(arr[i] < pivot) i++;
        else if(arr[j] >= pivot) j--;
        else {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp; 
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;

    quickSortUtil(arr, left, j-1);
    quickSortUtil(arr, j+1, right);
}

void quickSort(int *arr, int N) {
    quickSortUtil(arr, 0, N-1);
}

//--------------------------------------------------

int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);
    int arr[100];
    for(int i  = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("-----------\n");
    quickSort(arr, N);
    for(int i  = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}
