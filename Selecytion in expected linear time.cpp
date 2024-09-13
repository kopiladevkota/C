#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
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

// Function to select the k-th smallest element using randomized partitioning
int randomizedSelect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    // Randomly select pivot and partition the array
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    int pivotIndex = partition(arr, low, high);

    // Size of the left subarray
    int leftSize = pivotIndex - low + 1;

    // Check if the pivot is the k-th smallest element
    if (k == leftSize) {
        return arr[pivotIndex];
    } else if (k < leftSize) {
        return randomizedSelect(arr, low, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, high, k - leftSize);
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
    int arr[] = {8, 9, 3, 2, 4, 11, 20, 30, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5; // Find the 3rd smallest element (k-th smallest)

    printf("Original array:\n");
    printArray(arr, n);

    int kthSmallest = randomizedSelect(arr, 0, n - 1, k);

    printf("\nThe %d-th smallest element is: %d\n", k, kthSmallest);

    return 0;
}
