#include<stdio.h>
#include<stdlib.h>

int binSearch(int arr[], int l, int r, int x) {
    int mid;
    if(l <= r) {
        mid = l+(r-l)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x) {
            return binSearch(arr, l, mid-1, x);
        }
        else
            return binSearch(arr, mid+1, r, x);
    }
    return -1;
}

int findFrequency(int arr[], int n, int k) {
    int ind = binSearch(arr, 0, n-1, k);
    if(ind == -1){
        return 0;
    }
    int l = ind-1;
    int r = ind+1;
    int count = 1;
    while(l >= 0 && arr[l] == k) {
        l--;
        count++;
    }
    while(r < n && arr[r] == k) {
        r++;
        count++;
    }
    return count;
}

int main(void) {
    int i, k, size, *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    if(arr) {
        printf("Enter %d elements in sorted order: ", size);
        for(i=0; i<size; i++)
            scanf("%d", arr+i);
        printf("Enter element to find frequency: ");
        scanf("%d", &k);
        printf("Frequency of %d is %d", k, findFrequency(arr, size, k));
    }
    else {
        printf("Error in allocation memory!\n");
    }
    return 0;
}
