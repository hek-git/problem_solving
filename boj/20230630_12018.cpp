#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int main() {
    int n, m, P, L, num, ans = 0;
    cin >> n >> m;
    vector<int> l;

    for (int i = 0; i < n; i++) {
        cin >> P >> L;
        vector<int> p;

        for (int j = 0; j < P; j++) {
            cin >> num;
            p.push_back(num);
        }

        if (P < L) {
            l.push_back(1);
            continue;
        }

        sort(p.begin(), p.end(), compare);
        l.push_back(p[L - 1]);
    }

    sort(l.begin(), l.end());
    num = 0;
    for (auto a : l) {
        if (num + a > m) break;
        num += a;
        ans++;
    }
    cout << ans;
}