#include <bits/stdc++.h>

using namespace std;

// Computational cost: O(1)
// Memory cost: O(1)

long long pa_sum(long long lower, long long upper)
{
	int n = upper / lower;
	return (2*lower + (n - 1)*lower)*n/2;	
}

int main()
{
    int number;

    while (cin >> number) {
		number--;
		long long result = pa_sum(3, number) +
						   pa_sum(5, number) -
						   pa_sum(15, number);
        cout << result << endl;
    }
    return 0;
}
