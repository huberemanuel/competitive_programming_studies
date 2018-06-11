#include <bits/stdc++.h>

using namespace std;

int mdc(int num1, int num2) { int resto; do { resto = num1 % num2; num1 = num2; num2 = resto; } while (resto != 0); return num1; }
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
		cin >> a>>b;
		cout << mdc(a,b) <<endl;
	}
    
    return 0;
}
