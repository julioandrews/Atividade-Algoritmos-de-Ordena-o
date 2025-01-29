#ifndef _BUBBLE_SORT
#define _BUBBLE_SORT

#define false 0
#define true 1

typedef int bool;

void swap(Recipe *a, Recipe *b) {
    Recipe temp = *a;
    *a = *b;
    *b = temp;
}

int compareByPriority(const Recipe *a, const Recipe *b) {
    return a->priority - b->priority;
}

int compareByTime(const Recipe *a, const Recipe *b) {
    return a->time - b->time;
}

void bubbleSort(Recipe arr[], int n, int (*cmp)(const Recipe *, const Recipe *)) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (cmp(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

#endif