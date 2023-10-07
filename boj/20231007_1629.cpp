#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll A, B, C, ans;

int binary(ll n) {
    int cnt = 0;
    ll tmp = 1;
    while (true) {
        if (tmp * 2 > n) {
            break;
        }
        tmp *= 2;
        cnt++;
    }
    return cnt;
}

ll solve(ll n) {
    if(n == 0) return 1;
    if(n == 1) return A%C;

    ll exp = binary(n);
    ll left = n-(ll)pow(2, exp);
    ll tmp = A;
    for(int i = 0; i < exp; i++) {
        tmp = tmp * tmp % C;
    }
    return tmp * solve(left) % C;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;
    cout << solve(B);
}