#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, T, A, X, Y, begin = -1, end = -1, rest = 0, tam = 0;
	vector<int> taps;
	vector<int> numbers;
	
	cin >> N >> T >> A >> X >> Y;
	
	vector<int> rests(X, 0);
	
	for (int i = 0; i < T; i++) {
		int aux;
		cin >> aux;
		taps.push_back(aux);
	}
	
	while (begin == -1 && end == -1) {
		
		rest = (rest + A) % X;
		numbers.push_back(A);
		tam++;
		
		if (tam >= Y and rest == 0) rests[rest] = 0;
		if ((rests[rest] != 0 and (tam - rests[rest]) >= Y) or (tam >= Y and rest == 0)) {
			begin = rests[rest];
			end = tam - 1;
			break;
		}
		
		if ((rests[rest] == 0) or (rests[rest] >= 1 and (tam - rests[rest]) >= Y))
			rests[rest] = tam;
		
		int bit = A & 1;
		for (int i = 1; i < T; i++)
			bit ^= (A >> (taps[i])) & 1;
		
		A >>= 1;
		A |= bit << (N - 1);
	}
	
	cout << begin << " " << end << endl;
}

