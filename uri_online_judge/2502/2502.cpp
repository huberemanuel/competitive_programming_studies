#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C, N;

    while (cin >> C >> N) {

        cin.ignore();
        string cipher1, cipher2;
        getline(cin, cipher1);
        getline(cin, cipher2);

        map<char, char> dict;

        transform(cipher1.begin(), cipher1.end(), cipher1.begin(), ::toupper);
        transform(cipher2.begin(), cipher2.end(), cipher2.begin(), ::toupper);

        for (int i = 0; i < cipher1.size(); ++i) {
            dict[cipher2[i]] = cipher1[i];
            dict[cipher1[i]] = cipher2[i];
        }

        transform(cipher1.begin(), cipher1.end(), cipher1.begin(), ::tolower);
        transform(cipher2.begin(), cipher2.end(), cipher2.begin(), ::tolower);

        for (int i = 0; i < cipher1.size(); ++i) {
            dict[cipher2[i]] = cipher1[i];
            dict[cipher1[i]] = cipher2[i];
        }

        while (N--) {
            string text;
            getline(cin, text);

            for (auto c : text) {
                if (dict.find(c) != dict.end()) {
                    cout << dict[c];
                }
                else {
                    cout << c;
                }
            }

            cout << endl;
        }

        cout << endl;

    }

    return 0;
}