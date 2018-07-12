#include <bits/stdc++.h>

#define ui unsigned int

using namespace std;

int main()
{
  ui k;
  bool flag = false;

  while (cin >> k and k)
  {
    if (flag)
      cout << endl;
    flag = true;

    vector<int> v (k);

    for (ui i = 0; i < k; ++i)
      cin >> v[i];

    for (ui i = 0; i < k - 5; ++i)
     for (ui j = i + 1; j < k - 4; ++j)
       for (ui l = j + 1; l < k - 3; ++l)
         for (ui m = l + 1; m < k - 2; ++m)
           for (ui n = m + 1; n < k - 1; ++n)
             for (ui o = n + 1; o < k; ++o)
               printf("%d %d %d %d %d %d\n", v[i], v[j], v[l], v[m], v[n], v[o]);
  }

  return 0;
}
