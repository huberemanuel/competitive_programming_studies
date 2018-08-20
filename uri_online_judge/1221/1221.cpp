#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n; cin >> n;
    
    while (n--) {
        int a; cin >> a;
        
        if (a <= 1) {
            cout << "Not Prime" << endl; continue;
        }
        
        int count = 0;
        
        for (int i = 2; i <= sqrt(a); ++i) {
            if (a % i == 0) count++;
        }
        
        if (count == 0) cout << "Prime" << endl;
        else cout << "Not Prime" << endl;
        
    }
 
    return 0;
}

