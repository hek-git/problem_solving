#include <iostream>
#include <vector>

using namespace std;
int main() {
    int m, ans = 0;
    vector<int> money({500, 100, 50, 10, 5, 1});
    cin >> m;
    m = 1000 - m;
    for (auto a : money) {
        if (m / a >= 1) {
            ans = ans + (m / a);
            m %= a;
        }
    }
    cout << ans;
}