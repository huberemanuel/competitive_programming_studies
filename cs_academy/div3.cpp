#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, ans = 0;

    cin >> a;

    while(a > 1) {

        if(a == 2 or (a % 3) == 1) {
            a--;
        } else if((a % 3) == 0) {
            a /= 3;
        } else {
            a++;
        }

        ans++;

    }

    cout << ans << endl;

    return 0;

}
