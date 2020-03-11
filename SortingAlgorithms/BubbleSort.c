#include<stdio.h>
#include<stdbool.h>

void bubbleSort(int arr[], int n) {
    bool flag = false;
    int i,j;
    for(i=0; i<n; i++) {
        for(j = 0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)
            break;
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
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}

