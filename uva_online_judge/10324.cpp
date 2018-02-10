#include <bits/stdc++.h>

using namespace std;

int main()
{
    string number;
    int n, cases = 0;

    while (cin >> number)
    {
        cin >> n;

        cout << "Case " << ++cases << ":" << endl;

        for (int ni = 0;ni < n; ++ni)
        {
            int i, j;
            cin >> i >> j;

            int aux = min(i, j);
            j = max(i, j);
            i = aux;

            int flag = true;
            char c = number[i];

            for (;i <= j and flag;++i)
                flag = number[i] == c;

            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
