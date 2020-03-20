#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compareFunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool findPair(int arr[], int n, int x) {
    qsort(arr, n, sizeof(int), compareFunc);
    int l=0, r=n-1, sum;
    while(l < r) {
        sum = arr[l] + arr[r];
        if(sum == x)
            return 1;
        else if(sum < x)
            l++;
        else r--;
    }
    return false;
}

int main(void) {
    int size, x;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int i, arr[size];
    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("Enter sum to check: ");
    scanf("%d", &x);

    if(findPair(arr, size, x))
        printf("Found pair with sum %d\n", x);
    else
        printf("No pair with sum %d found\n", x);
    return 0;
}
