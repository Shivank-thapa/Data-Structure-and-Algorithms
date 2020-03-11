#include<stdio.h>

//partition function which works by choosing the last element as pivot
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int temp, i, j = l-1;
    for(i=l; i<r; i++) {
        if(arr[i] < pivot) {
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    j++;
    temp = arr[j];
    arr[j] = arr[r];
    arr[r] = temp;
    return j;
}


void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int pivot = partition(arr, l ,r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main(void) {
    int i, n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements to be sorted: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}

