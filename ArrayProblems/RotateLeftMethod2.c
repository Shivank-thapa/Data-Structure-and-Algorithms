#include<stdio.h>
#include<stdlib.h>

void reverse(int arr[], int l, int r) {
    int tmp;
    while(l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

void rotate(int arr[], int n, int d) {
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

void printArray(int arr[], int n) {
    int i;
    for(i=0 ; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int i, d, size, *arr;
    printf("Enter size: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if(arr) {
        printf("Enter %d elements: ", size);
        for(i=0; i<size; i++)
            scanf("%d", &arr[i]);
        printf("Enter rotation factor: ");
        scanf("%d", &d);
        d %= size;
        printf("Array before rotation: ");
        printArray(arr, size);

        rotate(arr, size, d);

        printf("Array after rotation: ");
        printArray(arr, size);
    }
    else {
        printf("Could not allocate memory!\n");
    }
    return 0;
}
