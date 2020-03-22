#include<stdio.h>
#include<stdlib.h>

int compareFunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findTriplets(int arr[], int n) {
    int i,l,r;

    qsort(arr, n, sizeof(int), compareFunc);
    for(i=0; i<n-1; i++) {
        l = i+1;
        r = n-1;
        while(l < r) {
            if(arr[i] + arr[l] + arr[r] == 0) {
                printf("(%d %d %d)\n", arr[i], arr[l], arr[r]);
                l++;
                r--;
            }
            else if(arr[i] + arr[l] + arr[r] < 0)
                l++;
            else
                r--;
        }
    }
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
        findTriplets(arr, size);
    }
    else {
        printf("Error in allocating memory!");
    }
    return 0;
}
