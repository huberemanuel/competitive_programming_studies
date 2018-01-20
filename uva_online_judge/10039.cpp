#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int aux;
        map<int, bool> numbers;

        cin >> aux;

        for (int i = 0; i < n - 1; ++i)
        {
            int a;
            cin >> a;
            numbers[abs(abs(aux) - abs(a))] = true;
            aux = a;
        }

        bool flag = true;

        for (int i = 1; i < n; ++i)
        {
            if (numbers.find(i) == numbers.end())
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;

    }

    return 0;
}
