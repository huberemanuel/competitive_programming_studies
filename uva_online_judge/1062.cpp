#include <bits/stdc++.h>

using namespace std;
 
int N, T = 0;
string inp;
stack<char> empty;
vector< stack<char> > containers;
 
void add_to_stack(int i) 
{
	
    for(unsigned int j = 0; j < containers.size(); j++) 
    {
        if(inp[i] <= containers[j].top()) 
        {
            containers[j].push(inp[i]);
            return;
        }
    }
    
    containers.push_back(empty);
    containers[containers.size() - 1].push(inp[i]);
 
}
 
int main() 
{
	
    while(cin >> inp, inp != "end") 
    {
        T++;
        N = static_cast<int>(inp.size());
        containers.clear();
 
        for(int i = 0; i < N; i++)
            add_to_stack(i);
        
        printf("Case %d: %lu\n", T, containers.size());
    }
    
    return 0;
}
