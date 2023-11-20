#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int coinChange(int *coins, int coinsSize, int amount) {
    if (amount < 1)
        return 0;
    int m = INT_MAX;
    int minCoins[amount+1];
    minCoins[0] = 0;
    for (int i = 1; i <= amount; ++i)
        minCoins[i] = m;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin = 0; coin < coinsSize; ++coin)
        {
            if (coins[coin] <= i)
            {
                minCoins[i] = minCoins[i] < 1 + minCoins[i- coins[coin]] ? minCoins[i] : 1+minCoins[i - coins[coin]];
            }
        }
    }

    if (minCoins[amount] == INT_MAX)
        return -1;
    
    return minCoins[amount];
}
int main()
{
    int n;
    printf("Enter the number of coins you have: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the values of the coins separated by spaces (e.g., 1 2 5): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    int amn;
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &amn);

    int result = coinChange(coins, n, amn);

    if (result == -1){
       printf("It is not possible to make change for the given amount using the provided coins.\n");
       printf("-1");
    }
    else{
        printf("Minimum number of coins required: %d\n", result);
    }
    return 0;
}
