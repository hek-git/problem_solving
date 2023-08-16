#include <algorithm>
#include <iostream>

using namespace std;

long long A, B, V, tmp, ans = 2000000000;
long long l = 1, r = 1000000000, mid;

int main() {
    cin >> A >> B >> V;

    while (l <= r) {
        mid = (l + r) / 2;
        tmp = A * mid - B * (mid - 1);
        if (tmp >= V) {
            ans = min(ans, mid);
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans;
}