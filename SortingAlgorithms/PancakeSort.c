#include<stdio.h>

void flip(int arr[], int j) {
    int temp, i=0;
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int findMaxIndex(int arr[], int n) {
    int i, maxIndex = 0;
    for(i=0; i<n; i++) {
        if(arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(int arr[], int n) {
    int i, maxIndex;

    for(i=n; i>1; i--) {
        maxIndex = findMaxIndex(arr, i);
        if(maxIndex != i-1) {
            flip(arr, maxIndex);
            flip(arr, i-1);
        }
    }
}

int main(void) {
    int i, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements to be sorted: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    pancakeSort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
