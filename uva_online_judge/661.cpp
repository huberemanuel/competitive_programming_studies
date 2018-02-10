nclude <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c, cases = 0;

    while (++cases)
    {
        int max_value = 0, sum = 0;
        cin >> n >> m >> c;
        if (n == 0 and m == 0 and c == 0) break;

        vector<int> consumption;
        vector<bool> devices(n, false);
        bool finish = false;

        for (int i = 0; i < n; ++i)
        {
            int aux; cin >> aux; consumption.push_back(aux);
        }

        for (int i = 0; i < m; ++i)
        {
            int aux; cin >> aux;

            devices[aux - 1] = !devices[aux - 1];

            if (devices[aux - 1])
                sum += consumption[aux - 1];
            else
                sum -= consumption[aux - 1];
            
	    finish = sum > c;

            max_value = max(max_value, sum);

        }

        cout << "Sequence " << cases << endl;

        if (finish)
            cout << "Fuse was blown." << endl;
        else
            cout << "Fuse was not blown." << endl << "Maximal power consumption was " << max_value << " amperes." << endl;

        cout << endl;

    }

    return 0;
}
