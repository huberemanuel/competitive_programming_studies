#include <bits/stdc++.h>

using namespace std;

int S, B, L, R;
int LS[1000100];
int RS[1000100];

int main()
{
	int s, b;
	
	while (cin >> s >> b and s and b)
	{
		
                for (int i = 0; i < s + 1; i++)
                {   
                     LS[i] = i - 1;
                     RS[i] = i + 1;
                }

		while (b--)
		{
			int begin, end;
			
			cin >> begin >> end;
	
			if (LS[begin] < 1) cout << "* ";
			else cout << LS[begin] << " ";
			
			if (RS[end] > s) cout << "*";
			else cout << RS[end];
			

                        LS[RS[end]] = LS[begin];
                        RS[LS[begin]] = RS[end];

			cout << endl;
		}
		
		
		cout << "-" << endl;
	}
	
	
	return 0;
}
