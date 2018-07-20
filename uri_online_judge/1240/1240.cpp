#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;

	while(n--) {
		int a, b; cin >> a >> b;
		while (true) {
			if (b == 0) { cout << "encaixa" << endl; break; }
			else if (a == 0 || a % 10 != b % 10) { cout << "nao encaixa" << endl; break; }
			a = a / 10;
			b = b / 10;
		}
	}
	return 0;
}
