#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    string alphabet;

    while (cin >> alphabet) {
        map<int, char> decode;
        for (int i = 0; i < alphabet.size(); ++i) {
            decode[i+1] = alphabet[i];
        }

        int N; cin >> N;
        while (N--) {
            int aux; cin >> aux;
            cout << decode[aux];
        }
        cout << endl;
    }

    return 0;
}