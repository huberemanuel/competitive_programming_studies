#include <bits/stdc++.h>

using namespace std;

int main()
{
	int pages;

	while (cin >> pages and pages)
	{
		int minPage = 1, maxPage = pages;
		
		cout << "Printing order for " << pages << " pages:" << endl;
		
		if (pages == 1) {
			cout << "Sheet 1, front: Blank, 1" << endl;
		}
		
		else {
			for (int i = 0; i < ceil(pages / 4.0); ++i)
			{
				cout << "Sheet " << i + 1 << ", front: ";

				if ((i == 0 and pages % 4 != 0) or (i == 1 and pages % 4 == 1))
					cout << "Blank, " << minPage++;
				else
					cout << maxPage-- << ", " << minPage++;
				cout << endl;
				
				cout << "Sheet " << i + 1 << ", back : ";
				if (i == 0 and pages % 4 > 0 and pages % 4 < 3)
					cout << minPage++ << ", Blank";
				else
					cout << minPage++ << ", " << maxPage--;
				cout << endl;
			}
		}
		
	}

	return 0;
}
