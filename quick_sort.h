#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>

int choosePivot(Recipe arr[], int low, int high) {
    int mid = (low + high) / 2;
    
    if (arr[low].priority > arr[mid].priority) swap(&arr[low], &arr[mid]);
    if (arr[low].priority > arr[high].priority) swap(&arr[low], &arr[high]);
    if (arr[mid].priority > arr[high].priority) swap(&arr[mid], &arr[high]);
    
    return mid;
}

int partition(Recipe arr[], int low, int high, int (*cmp)(const Recipe *, const Recipe *)) {

    int pivotIndex = choosePivot(arr, low, high);
    swap(&arr[pivotIndex], &arr[high]);
    
    Recipe pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (cmp(&arr[j], &pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Recipe arr[], int low, int high, int (*cmp)(const Recipe *, const Recipe *)) {
    if (low < high) {
        int pi = partition(arr, low, high, cmp);
        quickSort(arr, low, pi - 1, cmp);
        quickSort(arr, pi + 1, high, cmp);
    }
}

#endif
