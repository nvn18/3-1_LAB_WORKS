#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printTable(int knsk[][9], int n, int W) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d ", knsk[i][w]);
        }
        printf("\n");
    }
}

int knapsack(int W, int values[], int weights[], int n) {
    int i, j;
    
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (weights[j] > weights[j + 1]) {
                
                int t_weight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = t_weight;

                
                int t_value = values[j];
                values[j] = values[j + 1];
                values[j + 1] = t_value;
            }
        }
    }

    int knsk[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                knsk[i][j] = 0;
            else if (weights[i - 1] <= j)
                knsk[i][j] = max(values[i - 1] + knsk[i - 1][j - weights[i - 1]], knsk[i - 1][j]);
            else
                knsk[i][j] = knsk[i - 1][j];
        }
    }

    
    printf("THE 0/1 knapsack Table:\n");
    printTable(knsk, n, W);

    return knsk[n][W];
}

int main()
{
int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n];
    int weights[n];
    int W;

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int result = knapsack(W, values, weights, n);
    printf("\nMaximum value: %d\n", result);

    return 0;
}








