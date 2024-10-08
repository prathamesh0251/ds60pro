#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target)
            return mid; // Return the index of the target
        
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("Enter the number to search: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, size, target);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");
    
    return 0;
}