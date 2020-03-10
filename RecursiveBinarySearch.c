#include<stdio.h>

int search(int arr[], int l, int r, int key) {
    if(l <= r) {
        int mid = (l+r)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return search(arr, l, mid-1, key);
        else
            return search(arr, mid+1, r, key);
    }
    return -1;
}

int main(void) {
    int i, n, key;
    printf("Enter size of array ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int index = search(arr, 0, n, key);
    if(index != -1)
        printf("Element %d found at index %d\n", key,index);
    else
        printf("Element %d not found in array\n", key);
    return 0;
}

