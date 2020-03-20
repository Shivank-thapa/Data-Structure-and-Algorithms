#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int compareFunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findPair(int arr[], int n) {
    int l=0, r=n-1;
    int min_l=0, min_r=n-1;
    int sum, min_sum = INT_MAX;

    qsort(arr, n, sizeof(int), compareFunc);
    while(l < r) {
        sum = arr[l] + arr[r];
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum < 0)
            l++;
        else
            r--;
    }
    printf("Pair with sum closest to 0 is: (%d, %d)\n", arr[min_l], arr[min_r]);
}

int main(void) {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int i, arr[size];
    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    findPair(arr, size);
    return 0;
}
