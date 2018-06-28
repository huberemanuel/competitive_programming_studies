#include <bits/stdc++.h>

using namespace std;

int main()
{

  string s;

  while (cin >> s)
  {
    string::iterator it;
    stack<char> stk;
    int i = 0;
    for (;i < static_cast<int>(s.length()); ++i)
    {
      if (s[i] == '(')
        stk.push(s[i]);
      else if (s[i] == ')' and not stk.empty() and stk.top() == '(')
        stk.pop();
      else if (s[i] == ')')
        break;
    }

    if (i == static_cast<int>(s.length()) && stk.empty())
      cout << "correct" << endl;
    else
      cout << "incorrect" << endl;
  }

  return 0;
}
