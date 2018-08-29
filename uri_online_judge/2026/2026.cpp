// Knapsack 0 1 simples

#include <bits/stdc++.h>

using namespace std;

const int max_items = 101;
const int max_weight = 1001;

int w[max_items], v[max_items], K;
int dp[max_items][max_weight];

int knapsack(int i, int weight) {
    if (i < 0 || weight < 0) return 0;
    
    else if (weight - w[i] < 0) 
        dp[i][weight] = knapsack(i - 1, weight);
    
    else if (dp[i][weight] == -1)
        dp[i][weight] =  max(v[i] + knapsack(i - 1, weight - w[i]), 
                                    knapsack(i - 1, weight));
                    
    return dp[i][weight];
}

int main()
{
    int cases; cin >> cases;
    
    for (int c = 0; c < cases; ++c) {
        memset(dp, -1, sizeof(dp));
        int n, W; cin >> n >> W;
        for (int i = 0;i < n; ++i)
            cin >> v[i] >> w[i];
        
        cout << "Galho " << c + 1 << ":\n";
        cout << "Numero total de enfeites: " << knapsack(n - 1, W) << "\n\n";
    }

    return 0;
}
