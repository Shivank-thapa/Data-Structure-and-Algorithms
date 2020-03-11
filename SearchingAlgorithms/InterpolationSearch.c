#include<stdio.h>

int search(int arr[], int n, int key) {
    int l = 0, h = n-1;
    while(l <= h && arr[l] <= key && arr[h] >= key) {
        if(l == h) {
            if(arr[l] == key)
                return l;
            return -1;
        }

        int pos = l + ((double)(h-l)/(arr[h]-arr[l])*(key-arr[l]));
        if(arr[pos] == key)
            return pos;
        else if(arr[pos] < key)
            l = pos+1;
        else
            h = pos-1;
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
    int index = search(arr, n, key);
    if(index != -1)
        printf("Element %d found at index %d\n", key,index);
    else
        printf("Element %d not found in array\n", key);
    return 0;
}


