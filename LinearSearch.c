#include<stdio.h>

int search(int arr[], int n, int key) {
    int i;
    for(i=0; i<n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main(void) {
    int i, n, key;
    printf("Enter size of array ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int index = search(arr,n,key);
    if(index != -1)
        printf("Element %d found at index %d\n", key,index);
    else
        printf("Element %d not found in array\n", key);
    return 0;
}
