#include <bits/stdc++.h>

#define date pair<int, pair<int, int> >

using namespace std;

int days_in_month(int month) {
	map<int, int> m = {
		{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
	};
	return m[month];
}

bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

date nextDay(int day, int month, int year) {
	if (day == 31 && month == 12) {
		day = month = 1; year++;
	}
	else if (day == 28 and month == 2) {
		if (is_leap_year(year)) day++;
		else {
			day = 1; month++;
		}
	}
	else {
		day = max((day + 1) % (days_in_month(month) + 1), 1);
		if (day == 1) month++;
	}
	return make_pair(day, make_pair(month, year));
}

int main()
{
	int n;

	while (cin >> n and n) {
		int D, M, Y, C;
		int consec = 0, consump = 0, consec_n = 0, lastC = 0;
		date actual;
		for (int i = 0; i < n; ++i) {
			cin >> D >> M >> Y >> C;

			if (i > 0) {
				if (actual.first == D &&
				    actual.second.first == M &&
				    actual.second.second == Y) {
					consec++;
					consump += C - lastC;
					//cout << "Somando: " << C << " " << lastC << endl;
				}
			
			}

			actual = nextDay(D, M, Y);
			// cout << "Next day: " << actual.first << " " << actual.second.first << " " << actual.second.second << endl;
			lastC = C;
		}
		
		cout << consec << " " << consump << endl;
	}

	return 0;
}
