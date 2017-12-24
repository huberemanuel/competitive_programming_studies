#include <bits/stdc++.h>

using namespace std;

int main()
{
	string read;
	
	char board[8][8], board_aux[8][8];
	
	while (cin >> read)
	{
		int i = 0, j = 0;
		
		memset(board, '0', sizeof(board[0][0]) * 8 * 8);
		memset(board_aux, '0', sizeof(board_aux[0][0]) * 8 * 8);
		
		for (int k = 0; k < static_cast<int>(read.size()); k++)
		{
			char c = read[k];
			if (c == '/')
			{
				i++;
				j = 0;
			}
			else if (c >= '0' and c <= '9')
				j += c - '0';
			else
			{
				board[i][j] = c;
				j++;
			}
		}
		
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				char c = board[i][j];
				
				if (c == '0') continue;
				
				board_aux[i][j] = '1';

				if (c == 'p')
				{
					if (i + 1 < 8 and j + 1 < 8)
						board_aux[i + 1][j + 1] = '1';
					if (i + 1 < 8 and j - 1 > -1)
						board_aux[i + 1][j - 1] = '1';
				}
				else if (c == 'P')
				{
					if (i - 1 > -1 and j + 1 < 8)
						board_aux[i - 1][j + 1] = '1';
					if (i - 1 > -1 and j - 1 > -1)
						board_aux[i - 1][j - 1] = '1';
				}
				else if (c == 'K' or c == 'k')
				{
					if (i + 1 < 8)
						board_aux[i + 1][j] = '1';
					if (i - 1 > -1)
						board_aux[i - 1][j] = '1';
					if (j + 1 < 8)
						board_aux[i][j + 1] = '1';
					if (j - 1 > -1)
						board_aux[i][j - 1] = '1';
					if (i + 1 < 8 and j + 1 < 8)
						board_aux[i + 1][j + 1] = '1';
					if (i + 1 < 8 and j - 1 > -1)
						board_aux[i + 1][j - 1] = '1';
					if (i - 1 > -1 and j + 1 < 8)
						board_aux[i - 1][j + 1] = '1';
					if (i - 1 > -1 and j - 1 > -1)
						board_aux[i - 1][j - 1] = '1';
				}
				else if (c == 'N' or c == 'n')
				{
					if (i - 2 > -1 and j + 1 < 8)
						board_aux[i - 2][j + 1] = '1';
						
					if (i - 2 > -1 and j - 1 > -1)
						board_aux[i - 2][j - 1] = '1';
						
					if (i + 2 < 8 and j + 1 < 8)
						board_aux[i + 2][j + 1] = '1';
						
					if (i + 2 < 8 and j - 1 > -1)
						board_aux[i + 2][j - 1] = '1';
						
					if (i + 1 < 8 and j + 2 < 8)
						board_aux[i + 1][j + 2] = '1';
						
					if (i + 1 < 8 and j - 2 > -1)
						board_aux[i + 1][j - 2] = '1';
						
					if (i - 1 > -1 and j + 2 < 8)
						board_aux[i - 1][j + 2] = '1';
						
					if (i - 1 > -1 and j - 2 > -1)
						board_aux[i - 1][j - 2] = '1';
				}
				else if (c == 'R' or c == 'r' or c == 'Q' or c == 'q')
				{		
					for (int k = j + 1; k < 8; k++)
					{
						if (board[i][k] != '0') break;
						
						board_aux[i][k] = '1';
					}
					
					for (int k = j - 1; k > -1; k--)
					{
						if (board[i][k] != '0') break;
						
						board_aux[i][k] = '1';
					}
					
					for (int k = i + 1; k < 8; k++)
					{
						if (board[k][j] != '0') break;
						
						board_aux[k][j] = '1';
					}
					
					for (int k = i - 1; k > -1; k--)
					{
						if (board[k][j] != '0') break;
						
						board_aux[k][j] = '1';
					}
				}
				
				if (c == 'Q' or c == 'q' or c == 'B' or c == 'b')
				{
					int z = j + 1;
					for (int k = i + 1; k < 8 and z < 8; k++, z++)
					{
						if (board[k][z] != '0') break;
						
						board_aux[k][z] = '1';
					}
						
					z = j + 1;
					for (int k = i - 1; k > -1 and z < 8; k--, z++)
					{
						if (board[k][z] != '0') break;
						
						board_aux[k][z] = '1';
					}
					
					z = j - 1;
					for (int k = i + 1; k < 8 and z > -1; k++, z--)
					{
						if (board[k][z] != '0') break;
							
						board_aux[k][z] = '1';
					}

					z = j - 1;
					for (int k = i - 1; k > -1 and z > -1; k--, z--)
					{
						if (board[k][z] != '0') break;
						
						board_aux[k][z] = '1';
					}
				}
			}
		}
		
		int aux = 0;
		
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board_aux[i][j] == '0')
					aux++;
		
		cout << aux << endl;
	}
		
	return 0;
}
