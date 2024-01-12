#include <stdio.h>

void frequencySort(int arr[], int n) {
    // Count the frequency of each element
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Sort the array based on frequency
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (count[arr[j]] > count[arr[i]] || (count[arr[j]] == count[arr[i]] && arr[j] < arr[i])) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {4, 2, 6, 2, 6, 4, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    frequencySort(arr, n);

    printf("\nArray after frequency sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
