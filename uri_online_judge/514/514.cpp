#include <bits/stdc++.h>

using namespace std;

bool simulate(vector<int> permut)
{
    stack<int> S;
    int tam = static_cast<int>(permut.size());
	int j = 1;
	
    for (int i = 0; i < tam; ++i)
    {
	
        if (S.empty() or permut[i] > S.top())
        {        
            for (;j <= permut[i]; ++j)
                S.push(j);
        }

        if (permut[i] != S.top())
            return false;
            
        S.pop();
    }

    return true;
}

int main()
{
    int n;

    while (cin >> n, n != 0)
    {
		
        vector<int> permut;
        
        for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
            permut.push_back(a);
            
            if (i == 0 and a == 0)
                break;

            permut[i] = a;

            if (i == n - 1)
            {
                if (simulate(permut))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
				
                i = -1;
                permut.clear();
            }

		}
		cout << endl;

    }

    return 0;
}
