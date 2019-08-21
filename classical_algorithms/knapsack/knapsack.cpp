#include <iostream>
#include <cstring>

int v[] = {30, 10, 12};
int w[] = {15, 12, 18};
const int maxWeight = 30;
int dp[3][30];

int knapsack(int weight, int index)
{
    if (index < 0) return 0;

    else if (weight - w[index] < 0)
        dp[index][weight] = knapsack(weight, index - 1);

    else
        dp[index][weight] = std::max(knapsack(weight, index - 1),
                                v[index] + knapsack(weight - w[index], index - 1)
                            );
    return dp[index][weight];
}

int main()
{
    std::memset(dp, -1, sizeof(dp));
    std::cout << "Max value: " << knapsack(maxWeight, 2) << std::endl;

    return 0;
}
