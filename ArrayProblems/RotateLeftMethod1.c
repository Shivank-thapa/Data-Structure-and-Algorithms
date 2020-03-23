#include<stdio.h>
#include<stdlib.h>

void rotate(int arr[], int n, int d) {
    int i, j, temp;
    for(j=0; j<d; j++) {
        temp = arr[0];
        for(i=0; i<n-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;
    }
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
