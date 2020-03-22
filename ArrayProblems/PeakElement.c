#include<stdio.h>
#include<stdlib.h>

int findPeak(int arr[], int left, int right, int n) {
    int mid;
    mid = left + (right - left)/2;

    if((mid == 0 && arr[mid+1] <= arr[mid] || (mid == n-1 && arr[mid-1] <= arr[mid]) || (arr[mid-1] <= arr[mid] && arr[mid+1] <= arr[mid])))
        return mid;
    else if(arr[mid-1] > arr[mid])
        return findPeak(arr, left, mid-1, n);
    else
        return findPeak(arr, mid+1, right, n);
}

int main(void) {
    int i, size, *arr;
    printf("Enter array size: ");
    scanf("%d", &size);

    arr = (int *)malloc(size *sizeof(int));

    if(arr) {
        printf("Enter %d elements: ", size);
        for(i=0; i<size; i++)
            scanf("%d", &arr[i]);
        int index = findPeak(arr, 0, size-1, size);
        printf("Peak element is: %d at index: %d", arr[index], index);
    }
    return 0;
}
