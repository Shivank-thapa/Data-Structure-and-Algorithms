#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct Heap {
    int arr[SIZE];
    int heapSize;
}Heap;

Heap *newHeap(int n){
    Heap *h = (Heap *)malloc(sizeof(Heap));

    h->heapSize = n;
    return h;
}

void maxHeapify(Heap *heap, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < heap->heapSize && heap->arr[left] > heap->arr[largest])
        largest = left;
    if(right < heap->heapSize && heap->arr[right] > heap->arr[largest])
        largest = right;

    if(largest != i) {
        int temp = heap->arr[largest];
        heap->arr[largest] = heap->arr[i];
        heap->arr[i] = temp;
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(Heap *heap, int n) {
    int i;
    for(i=n/2-1; i>=0; i--)
        maxHeapify(heap, i);
}

int extractMax(Heap *heap) {
    if(heap->heapSize < 1) {
        printf("Heap is empty!\n");
        return -1;
    }
    int max = heap->arr[0];
    int temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->heapSize-1];
    heap->arr[heap->heapSize-1] = temp;
    heap->heapSize--;
    maxHeapify(heap, 0);
    return max;
}


void findLargestK(int arr[], int size, int k) {
    int i;

    Heap *heap = newHeap(size);

    for(i=0; i<size; i++) {
        heap->arr[i] = arr[i];
    }

    buildMaxHeap(heap, size);

    for(i=0; i<k; i++)
        printf("%d ", extractMax(heap));
}

int main(void) {
    int i, size, k, *arr;
    printf("Enter size: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if(arr) {
        printf("Enter %d elements: ", size);
        for(i=0; i<size; i++)
            scanf("%d", &arr[i]);
        printf("Enter k: ");
        scanf("%d", &k);
        if(k > size) {
            printf("k cannot be greater than array size\n");
            exit(1);
        }
        findLargestK(arr, size, k);
    }
    else {
        printf("Could not allocate memory!");
    }
    return 0;
}
