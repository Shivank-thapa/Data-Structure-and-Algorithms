#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void findMaxTripletSum(int arr[], int n) {
    int i;
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int thirdMax = INT_MIN;

    for(i=0; i<n; i++) {
        if(arr[i] > max) {
            thirdMax = secondMax;
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax) {
            thirdMax = secondMax;
            secondMax = arr[i];
        }
        else if(arr[i] > thirdMax) {
            thirdMax = arr[i];
        }
    }
    printf("Max triplet sum of (%d, %d, %d) is %d", max, secondMax, thirdMax, max+secondMax+thirdMax);
}

int main(void){
    int i, size, *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(arr));

    if(arr) {
        printf("Enter %d elements: ", size);
        for(i=0; i<size; i++)
            scanf("%d", arr+i);
        findMaxTripletSum(arr, size);
    }
    else {
        printf("Error in allocating memory!");
    }
    return 0;
}
