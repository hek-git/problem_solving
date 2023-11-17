#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int r1, int r2) {
    ll answer = 0;
    for (ll y = 1; y <= r2; y++) {
        ll x1 = (ll)ceil(sqrt((ll)r1 * r1 - y * y));
        ll x2 = (ll)sqrt((ll)r2 * r2 - y * y);
        answer = answer + (x2 - x1 + 1);
    }
    return answer * 4;
}