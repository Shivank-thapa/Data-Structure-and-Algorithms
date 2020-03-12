#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
    int value;
    int weight;
}Item;

int comparator(const void *p, const void *q) {
    double x = ((double)(((Item *)q)->value)/(((Item *)q)->weight));
    double y = ((double)(((Item *)p)->value)/(((Item *)p)->weight));
    return x-y;
}

double findMaxProfit(int W, Item items[], int n) {
    double maxProfit = 0;
    int i, currWeight = 0;

    for(i=0; i<n; i++) {
            if(currWeight + items[i].weight <= W) {
                currWeight += items[i].weight;
                maxProfit += items[i].value;
            }
            else {
                maxProfit += ((double)(W - currWeight))/(items[i].weight) * items[i].value;
                break;
            }
    }
    return maxProfit;
}

int main(void) {
    int W, i, n;
    printf("Enter weight of knapsack: ");
    scanf("%d", &W);

    printf("Enter number of items: ");
    scanf("%d",&n);

    Item items[n];

    printf("Enter value and weight of %d items: ", n);
    for(i=0; i<n; i++)
        scanf("%d %d", &items[i].value, &items[i].weight);

    //sort items in decreasing order of value/weight
    qsort(items, n, sizeof(Item), comparator);

    printf("Max profit is: %f", findMaxProfit(W, items, n));

    return 0;
}
