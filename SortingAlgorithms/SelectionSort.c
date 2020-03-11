#include<stdio.h>

void selectionSort(int arr[], int n){
    int i,j,minIndex;
    for(i=0; i<n; i++) {
        minIndex = i;
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(void) {
    int i, n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements to be sorted: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}


