#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n >= 86) {
        cout << "A";
    }
    else if (n >= 61) {
        cout << "B";
    }
    else if (n >= 36) {
        cout << "C";
    }
    else if (n >= 1) {
        cout << "D";
    }
    else {
        cout << "E";
    }

    cout << endl;

    return 0;
}