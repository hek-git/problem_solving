#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int x,int y) {
    ll answer = 0;
    for(ll i = 1; i <= y; i++){
        ll num = (ll)ceil((double)i * (double)x / (double)y);
        answer = answer + ((ll)x - num);
    }
    return answer * 2;
}