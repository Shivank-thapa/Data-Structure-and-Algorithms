#include<stdio.h>

void sort(int arr[], int size) {
    int i, c0=0, c1=0, c2=0;
    for(i=0; i<size; i++) {
        switch(arr[i]) {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        }
    }
    i=0;
    while(c0 > 0) {
        arr[i++] = 0;
        c0--;
    }
    while(c1 > 0) {
        arr[i++] = 1;
        c1--;
    }
    while(c2 > 0) {
        arr[i++] = 2;
        c2--;
    }
}

int main(void) {
    int i, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d array elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);
    sort(arr, size);

    printf("Sorted array is: ");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    return 0;
}
