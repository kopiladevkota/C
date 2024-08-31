#include <stdio.h>

// Recursive function to implement Binary Search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }

        // If the element is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        // Otherwise, the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {4, 13, 48, 130, 240};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter the value to be searched: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}
