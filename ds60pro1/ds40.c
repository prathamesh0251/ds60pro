#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the element is present at mid
        if (arr[mid] == target)
            return mid;

        // If the element is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }
    return -1; // Element not found
}

// Main function
int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
