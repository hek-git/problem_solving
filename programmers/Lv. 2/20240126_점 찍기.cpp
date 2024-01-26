#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int k, int d) {
    ll answer = 0, d_squared = (ll)d * (ll)d;
    for(ll a = 0; a * (ll)k <= d; a++){
        ll y_squared = a * (ll)k * a * (ll)k;
        answer = answer + 1 + ((ll)sqrt(d_squared - y_squared)) / (ll)k;
    }
    return answer;
}