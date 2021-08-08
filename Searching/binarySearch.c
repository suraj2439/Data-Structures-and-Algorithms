#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//-----------------------------------------------------------------

int binarySearchUtil(int *arr, int left, int right, int data) {
    int mid = left+(right-left)/2;
    if(left > right) return -1;
    
    if(arr[mid] == data) return mid;
    else if(data > arr[mid]) return binarySearchUtil(arr, mid+1, right, data);
    else return binarySearchUtil(arr, left, mid-1, data);
}

int search(int *arr, int N, int data) {
    binarySearchUtil(arr, 0, N-1, data);
}

//-----------------------------------------------------------------

int lowerBoundUtil(int *arr, int left, int right, int data) {
    int mid = left + (right - left)/2;
    if(left > right) return left;
    
    if(data > arr[mid]) return lowerBoundUtil(arr, mid+1, right, data);
    else return lowerBoundUtil(arr, left, mid-1, data);
}

int lowerBound(int *arr, int N, int data) {
    return lowerBoundUtil(arr, 0, N-1, data);
}

//-----------------------------------------------------------------

int upperBoundUtil(int *arr, int left, int right, int data) {
    int mid = left+(right-left)/2;
    if(left > right) return left;

    if(data < arr[mid]) upperBoundUtil(arr, left, mid-1, data);
    else return upperBoundUtil(arr, mid+1, right, data);
}

int upperBound(int *arr, int N, int data) {
    return upperBoundUtil(arr, 0, N-1, data);
}

//-----------------------------------------------------------------

int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);
    printf("-------\n");
    int arr[100];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("-------\n");
    int data;
    scanf("%d", &data);
    printf("%d\n", lowerBound(arr, N, data));
    return 0;
}
