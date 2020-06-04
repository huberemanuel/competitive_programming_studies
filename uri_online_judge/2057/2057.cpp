#include <bits/stdc++.h>

using namespace std;

int main()
{
    int S, T, F;

    cin >> S >> T >> F;

    if (S == 0) {
        S = 24;
    }

    cout << (S + T + F) % 24 << endl;

    return 0;
}