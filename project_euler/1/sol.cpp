#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number;

    while (cin >> number) {
        long long _sum = 0;
        for (int i = 2; i < number; ++i) {
            if (i % 3 == 0 || i % 5 == 0) {
                _sum += i;
            }
        }
        cout << _sum << endl;
    }
    return 0;
}
