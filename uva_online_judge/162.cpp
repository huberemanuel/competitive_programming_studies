#include <bits/stdc++.h>

using namespace std;

map<char, int> cards = {{'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}};

int main()
{
    string aux;

    while (cin >> aux and static_cast<int>(aux.find("#")) == -1)
    {
        vector<string> dealer, non_dealer;
        deque<string> heap;
        bool control = false;

        for (int i = 0; i < 52; ++i)
        {
            if (control)
                dealer.push_back(aux);
            else
                non_dealer.push_back(aux);
            control = !control;
            if (i != 51)
				cin >> aux;
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
            
            if ((control and dealer.empty()) or (!control and non_dealer.empty())) break;
			
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

        int player = !control ? 1 : 2;
        printf("%d %2d\n", player, static_cast<int>(max(dealer.size(), non_dealer.size())));

    }

    return 0;
}
