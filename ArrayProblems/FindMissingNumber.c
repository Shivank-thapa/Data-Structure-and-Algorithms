#include<stdio.h>

int findMissing(int arr[], int n) {
    int i, x1=arr[0], x2=1;
    for(i=1; i<n-1; i++)
        x1 ^= arr[i];

    for(i=2; i<=n; i++)
        x2 ^= i;

    return x1^x2;
}

int main(void) {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int i, arr[size];
    printf("Enter %d elements in range 1 to %d with one element missing: ", size, size+1);
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    printf("%d",findMissing(arr, size+1));
    return 0;
}
