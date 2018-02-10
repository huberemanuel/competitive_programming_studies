#include <bits/stdc++.h>

using namespace std;

struct Player
{
	int ID;
	int score;
	int problems_solved;
	map<int, int> problems;
	map<int, bool> problems_accepted;
	bool tried = false;
};

bool CompareData(const Player& A, const Player& B)
{
    return (A.problems_solved > B.problems_solved) ||
           ((A.problems_solved == B.problems_solved) && (A.score < B.score)) || 
           ((A.problems_solved == B.problems_solved) && (A.score == B.score) &&
              (A.ID < B.ID));
}

int main()
{
	int cases;
	
	cin >> cases;
	
	for (int c = 0; c < cases; c++)
	{
		vector<Player> players (101);
		
		scanf("\n");
		
		string line;
		
		while (getline(cin, line) and !line.empty())
		{
			stringstream stream (line);
			int contestant, problem, time;
			char L;
			stream >> contestant >> problem >> time >> L;
			
			players[contestant].ID = contestant;
			players[contestant].tried = true;
			
			if (L == 'C' and !players[contestant].problems_accepted[problem])
			{
				players[contestant].score += players[contestant].problems[problem] + time;
				players[contestant].problems_solved++;
				players[contestant].problems_accepted[problem] = true;
			}
			else if (L == 'I' and !players[contestant].problems_accepted[problem])
			{
				players[contestant].problems[problem] += 20;
				players[contestant].problems_accepted[problem] = false;
			}
		}
		
		sort(players.begin(), players.end(), CompareData);
		
		if (c > 0)
			cout << endl;
			
		for (int i = 0; i < static_cast<int>(players.size()); i++)
		{
			if (players[i].tried)
				cout << players[i].ID << " " << players[i].problems_solved << " " << players[i].score << endl;
		}
		
	}
	
	return 0;
}
