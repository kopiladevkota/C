#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to generate a random pivot and partition the array
int randomPartition(int arr[], int low, int high) {
    // Generate a random index between low and high
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    
    // Swap arr[random] with arr[high]
    swap(&arr[random], &arr[high]);
    
    // Perform partition using the last element as pivot (same as regular partition)
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Randomized QuickSort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = randomPartition(arr, low, high);

        // Separately sort elements before partition and after partition
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {210, 7, 88, 39, 1, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
