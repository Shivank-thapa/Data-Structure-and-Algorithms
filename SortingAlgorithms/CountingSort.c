#include<stdio.h>
#include<string.h>

int findMax(int arr[], int n) {
    int i, max = arr[0];
    for(i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n){
    int range, i, res[n];
    range = findMax(arr, n);
    int count[range+1];
    memset(count, 0, sizeof(count)); //Initialize count array as 0

    for(i=0; i<n; i++)
        count[arr[i]]++;

    for(i=1; i<=range; i++)
        count[i] += count[i-1];

    for(i=0; i<n; i++) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(i=0; i<n; i++)
        printf("%d ", res[i]);
}

int main(void) {
    int i, n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements to be sorted: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Sorted array: ");
    countingSort(arr, n);
    return 0;
}


