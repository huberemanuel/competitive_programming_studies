#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, xp, yp, xa, ya;

    while (cin >> N >> M) {

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int aux; cin >> aux;
                if (aux == 1) {
                    xp = i;
                    yp = j;
                }
                else if (aux == 2) {
                    xa = i;
                    ya = j;
                }
            }
        }

        cout << abs(xa - xp) + abs(ya - yp) << endl;

    }

    return 0;
}