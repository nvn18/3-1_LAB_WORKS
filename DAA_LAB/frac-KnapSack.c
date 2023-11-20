#include <stdio.h>

void fractionalKnsk(int w[], int prof[], int n, int cap) {
    double r[n];
    int i, j;

    // Calculate profit-to-weight ratios
    for (i = 0; i < n; i++) {
        r[i] = (double)prof[i] / w[i];
    }

    // Sorting items and ratios in descending order using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (r[j] < r[j + 1]) {
                // Swaping ratios
                double temp_r = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp_r;

                // Swaping weights
                int temp_w = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp_w;

                // Swaping profits
                int temp_prof = prof[j];
                prof[j] = prof[j + 1];
                prof[j + 1] = temp_prof;
            }
        }
    }

    double total_prof = 0.0;
    int curr_w = 0;

    // Printing the table header
    printf("%-10s %-10s %-10s %-15s %-15s\n", "Item", "Weight", "Profit", "remain_w", "remain_cap");

    // Printing the arrangement of weights, profits, and remaining weights in a table
    for (i = 0; i < n; i++) {
        int remain_w = w[i];
        int remain_cap = cap - curr_w;

        if (curr_w + w[i] <= cap) {
            // Take the whole item
            curr_w += w[i];
            total_prof += prof[i];
            remain_w = 0;
        } else {
            // Take a fraction of the item
            double fraction = (double)remain_cap / w[i];
            curr_w += remain_cap;
            total_prof += fraction * prof[i];
            remain_w -= remain_cap;
        }
        
        printf("%-10d %-10d %-10d %-15d %-15d\n", i + 1, w[i], prof[i], remain_w, remain_cap);
    }

    printf("\nTotal profit: %.2lf\n", total_prof);
}

int main() {
    
    int n;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int prof[n];
    int w[n];
    int cap;

    printf("Enter the profit of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prof[i]);
    }

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &cap);
    
    
    /*int w[] = {1,3,5,4,1,3,2};
    int prof[] = {5,10,15,7,8,9,4};
    int cap = 15;
    int n = sizeof(w) / sizeof(w[0]);*/

    fractionalKnsk(w, prof, n, cap);

    return 0;
}



