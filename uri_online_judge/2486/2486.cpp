#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;

    map<string, int> table;

    table["suco de laranja"] = 120;
    table["morango fresco"] = 85;
    table["mamao"] = 85;
    table["goiaba vermelha"] = 70;
    table["manga"] = 56;
    table["laranja"] = 50;
    table["brocolis"] = 34;

    while (cin >> T && T != 0) {
        int total = 0;

        while (T--) {
            int k;
            string aux;
            cin >> k;
            cin.ignore();
            getline(cin, aux);
            
            total += table[aux] * k;
        }

        if (total < 110) {
            cout << "Mais " << 110 - total << " mg" << endl;
        }
        else if (total <= 130) {
            cout << total << " mg" << endl;
        }
        else {
            cout << "Menos " << total - 130 << " mg" << endl;
        }

    }

    return 0;
}