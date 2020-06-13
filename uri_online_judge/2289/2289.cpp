#include <bits/stdc++.h>

using namespace std;

int main() 
{
    unsigned long long X, Y;

    while (scanf("%llu %llu", &X, &Y) && (X || Y)) {

        unsigned long long i = 0;
        int dist = 0;

        // cout << X << " " << Y;
        while (i < 64) {
            if ((X & (1ULL << i)) ^ (Y & (1ULL << i))) {
                dist++;
            }
            i++;
        }

        printf("%d\n", dist);
        // cout << dist << endl;
    }

    return 0;
}