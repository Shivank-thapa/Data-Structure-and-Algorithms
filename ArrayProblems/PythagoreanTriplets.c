#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int cmpFunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findPythagoreanTriplet(int arr[], int n) {
    int i;
    int a, b, c;

    for(i=0; i<n; i++)
        arr[i] *= arr[i];

    qsort(arr, n, sizeof(int), cmpFunc);

    for(i=n-1; i>1; i--) {
        c = i;
        a = 0,
        b = i-1;
        while(a < b) {
            if(arr[a] + arr[b] == arr[c]){
                printf("Found pythagorean triplet (%d, %d, %d)\n", (int)sqrt(arr[a]), (int)sqrt(arr[b]), (int)sqrt(arr[c]));
                return;
            }
            if(arr[a] + arr[b] > arr[c])
                b--;
            else
                a++;
        }
    }
    printf("Could not find a pythagorean triplet.\n");
}

int main(void) {
    int i, size, *arr;
    printf("Enter size: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if(arr) {
        printf("Enter %d elements: ", size);
        for(i=0; i<size; i++)
            scanf("%d", arr+i);
        findPythagoreanTriplet(arr, size);
    }
    else {
        printf("Could not allocate memory!\n");
    }
    return 0;
}
