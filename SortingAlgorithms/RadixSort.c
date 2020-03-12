#include<stdio.h>

int findMax(int arr[], int n) {
    int i, max = arr[0];
    for(i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int place) {
    int i, res[n];
    int count[10] = {0};

    for(i=0; i<n; i++) {
        count[(arr[i]/place)%10]++;
    }

    for(i=1; i<10; i++)
        count[i] += count[i-1];

    for(i=n-1; i>=0; i--) {
        res[count[(arr[i]/place)%10] - 1] = arr[i];
        count[(arr[i]/place)%10]--;
    }

    for(i=0; i<n; i++) {
        arr[i] = res[i];
    }
}

void radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    int place = 1;

    while(max) {
        countSort(arr, n, place);
        max /= 10;
        place *= 10;
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
    radixSort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
