#include <stdio.h>

// Function to implement Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[] = {12, 3, 47, 310, 401};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter the value to be searched: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}
