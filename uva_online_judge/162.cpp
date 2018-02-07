#include <bits/stdc++.h>

using namespace std;

map<char, int> cards = {{'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}};

int main()
{
    string line;

    while (getline(cin, line) and line != "#")
    {
        stringstream  linestream (line);
        vector<string> dealer, non_dealer;
        deque<string> heap;
        bool control = false, end_game = false;

        for (int i = 0; i < 13; ++i)
        {
            string aux;
            linestream >> aux;
            if (control)
                dealer.push_back(aux);
            else
                non_dealer.push_back(aux);
            control = !control;
        }

        for (int i = 0; i < 3; ++i)
        {
            getline(cin, line);
            stringstream linestream(line);
            for (int j = 0; j < 13; ++j)
            {
                string aux;
                linestream >> aux;
                if (control)
                    dealer.push_back(aux);

                else
                    non_dealer.push_back(aux);
                control = !control;
            }
        }
        
        // control = true -> dealer playing
        // control = false -> non_dealer playing
        control = false;
        int cont_card = 1;
        bool special = false;

        heap.clear();

        string played = "";

        while (true)
        {
            if (cont_card == 0)
            {
                if (special)
                {

                    if (control)
                    {
                        non_dealer.insert(non_dealer.begin(), heap.begin(), heap.end());
                    }
                    else
                    {
                        dealer.insert(dealer.begin(), heap.begin(), heap.end());
                    }
                    heap.clear();
                }
                control = !control;
                cont_card = 1;
                special = false;
            }

			end_game = dealer.empty() || non_dealer.empty();
			if (end_game) break;
			
            if (control)
            {
                played = dealer.back();
                dealer.pop_back();
            }
            else
            {
                played = non_dealer.back();
                non_dealer.pop_back();
            }

            heap.push_front(played);
            cont_card--;

            if (cards.find(played[1]) != cards.end())
            {
                special = true;
                cont_card = cards[played[1]];
                control = !control;
            }
        }

        int player = dealer.empty() ? 2 : 1;
		cout << "heap: " << max(dealer.size(), non_dealer.size()) + heap.size() << endl;
        cout << player << " " << max(dealer.size(), non_dealer.size()) << endl;

    }

    return 0;
}
