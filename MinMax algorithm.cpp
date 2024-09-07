#include <stdio.h>

// Function to find minimum and maximum using recursion
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    findMinMax(arr, low, mid, &leftMin, &leftMax);
    findMinMax(arr, mid + 1, high, &rightMin, &rightMax);

    *min = (leftMin < rightMin) ? leftMin : rightMin;
    *max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int arr[] = {100, 121, 4245, 231, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);

    return 0;
}
