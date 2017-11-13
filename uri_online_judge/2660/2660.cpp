#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ull mdc(ull a, ull b) {
    if (a == 0) return b;
    else return mdc(b % a, a);
}

ull mmc(ull a, ull b) {
    return a * b / mdc(a, b);
}

int main() {

    int N, L;
    ull c = 1, best, lifeTime = 1;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        ull n;
        cin >> n;
        c = mmc(c, n);
    }

    best = c;

    for (int i = 1; i <= L; i++) {
        ull aux = mmc(c, i);

        if (aux > best && aux <= L) {
            best = aux;
            lifeTime = i;
        }
    }

    cout << lifeTime << endl;

    return 0;
}

