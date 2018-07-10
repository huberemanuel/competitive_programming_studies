#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

ull calls;

ull fibo(ull n)
{
	calls++;
    if (n <= 1ull )
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	
	cin >> n;
	
	while (n--)
	{
		int x;
		calls = 0;
		cin >> x;
		ull result = fibo(x);
		printf("fib(%d) = %llu calls = %llu\n", x, calls - 1, result);
	}
	
	return 0;
}
