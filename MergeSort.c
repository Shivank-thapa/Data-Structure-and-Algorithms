#include<stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int i,j,k;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(i=0; i<n2; i++)
        R[i] = arr[mid+i+1];
    i=0;
    j=0;
    k=l;
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
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
    mergeSort(arr, 0, n-1);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}

