#include<stdio.h>

int merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int i, j, k, L[n1], R[n2], count=0;

    for(i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(j=0; j<n2; j++)
        R[j] = arr[m+1+j];

    i=0; j=0; k=l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            count += (m+1)-(l+i);
        }
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
    return count;
}

int mergeSort(int arr[], int left, int right) {
    int count=0, mid;
    if(left < right) {
        mid = (left+right)/2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid+1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

int main(void) {
    int i, size;
    printf("Enter array size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d array elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);
    printf("Number of inversions are: %d\n", mergeSort(arr, 0, size-1));
    return 0;
}
