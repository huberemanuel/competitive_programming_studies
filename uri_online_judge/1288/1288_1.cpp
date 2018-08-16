#include <bits/stdc++.h>

using namespace std;

#define MAX 55

int values[MAX], weights[MAX], dp[MAX][110];
int n, k;

int knapsack(int i, int w) {
	if (i == n || w + weights[i] > k) return 0; 
	if (dp[i][w] == -1)
		dp[i][w] = max(values[i] + knapsack(i + 1, w + weights[i]),
			        knapsack(i + 1, w));
	return dp[i][w];
}

int main() {
	
	int c; cin >> c;

	while (c--) {
		int r; cin >> n;
		for(int i = 0;i < n; ++i) {
			int a, b; cin >> a >> b;
			values[i] = a; weights[i] = b;
		}
		cin >> k >> r;
		memset(dp, -1, sizeof(dp));
		int ans = knapsack(0, 0);
		cout << dp[0][k] << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) cout << dp[i][j] << "\t";
			cout << endl;
		}
		if (ans < r) cout << "Falha na missao" << endl;
		else cout << "Missao completada com sucesso" << endl;
	}

	return 0;
}
