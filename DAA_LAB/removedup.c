#include <stdio.h>

void removeDuplicates(int arr[], int *size) {
    int i, j, k;

    // Traverse the array
    for (i = 0; i < *size; i++) {
        // Check if arr[i] is already present in the result array
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }

        // If arr[i] is not present in the result array, add it
        if (j == i) {
            arr[k++] = arr[i];
        }
    }

    // Update the size to the number of unique elements
    *size = k;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 1, 6, 7, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Remove duplicates
    removeDuplicates(arr, &size);

    // Print the array after removing duplicates
    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
