#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinHeap {
    int *arr;
    int capacity;
    int heapSize;
}MinHeap;

MinHeap *newMinHeap(int n) {
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->arr = (int *)malloc(n * sizeof(int));
    h->capacity = n;
    h->heapSize = 0;
    
    return h;
}

int left(int i) {
    return (2*i + 1);
}

int right(int i) {
    return (2*i + 2);
}

int parent(int i) {
    return ((i-1)/2);
}

void minHeapify(MinHeap *h, int i) {
    int tmp, smallest = i;
    int l = left(i);
    int r = right(i);
    if(l < h->heapSize && h->arr[l] < h->arr[smallest])
        smallest = l;
    if(r < h->heapSize && h->arr[r] < h->arr[smallest])
        smallest = r;
    if(smallest != i) {
        tmp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = tmp;
        minHeapify(h, smallest);
    }
}

void insertKey(MinHeap *h, int k) {
    int i, tmp;
    if(h->capacity == h->heapSize) {
        printf("Heap is full!\n");
        return;
    }
    i = h->heapSize;
    h->arr[h->heapSize] = k;
    h->heapSize++;
    
    while(i != 0 && h->arr[parent(i)] > h->arr[i]) {
        tmp = h->arr[i];
        h->arr[i] = h->arr[parent(i)];
        h->arr[parent(i)] = tmp;
        i = parent(i);
    }
}

int getMin(MinHeap *h) {
    return h->arr[0];
}

int extractMin(MinHeap *h) {
    if(h->heapSize == 0)
        return INT_MAX;
    if(h->heapSize == 1) {
        h->heapSize--;
        return h->arr[0];
    }
    
    int tmp = h->arr[0];
    h->arr[0] = h->arr[h->heapSize-1];
    h->heapSize--;
    
    minHeapify(h, 0);
    return tmp;
}



int main(void) {
	MinHeap *h = newMinHeap(10);
	insertKey(h,3);
	insertKey(h,2);
	insertKey(h,15);
	insertKey(h,5);
	insertKey(h,4);
	insertKey(h,45);
	printf("Root is: %d\n", getMin(h));
	printf("Extract Min: %d\n",extractMin(h));
	printf("Extract Min: %d\n", extractMin(h));
	printf("Root is: %d\n", getMin(h));
	return 0;
}


