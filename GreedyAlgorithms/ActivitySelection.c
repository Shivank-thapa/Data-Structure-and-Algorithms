#include<stdio.h>
#include<stdlib.h>

typedef struct Activity {
    int start;
    int finish;
}Activity;

int comparator(const void *p, const void *q) {
    return (((Activity *)p)->finish - ((Activity *)q)->finish);
}

int main(void){
    int i, n, j;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    Activity activities[n];

    printf("Enter start and finish times of %d activities: ",n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &(activities[i].start), &(activities[i].finish));
    }

    qsort(activities, n, sizeof(Activity), comparator);

    i=0;
    printf("Activities that can be completed are: ");
    printf("(%d, %d) ", activities[i].start, activities[i].finish);

    for(j=1; j<n; j++) {
        if(activities[j].start >= activities[i].finish) {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i=j;
        }
    }
    return 0;
}
