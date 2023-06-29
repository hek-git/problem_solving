#include <iostream>

using namespace std;
int main() {
    int X, Y;
    long long W, S, ans = 0;
    cin >> X >> Y >> W >> S;
    int max_p = max(X, Y), min_p = min(X, Y), left = max_p - min_p;
    if (2 * W < S) {
        ans += (X + Y) * W;
    } else if (W <= S) {
        ans += S * min_p ;
        ans += left * W;
    } else if (S < W) {
        ans += S * min_p;
        if (left % 2)
            ans += S * (left - 1) + W;
        else
            ans += S * left;
    }
    cout << ans;
}