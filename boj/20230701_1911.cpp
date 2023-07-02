#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int main() {
    int N, L, num, ans = 0;
    vector<pair<int, int>> n;
    vector<pair<int, int>> list;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int first, second;
        cin >> first >> second;
        n.push_back(make_pair(first, second));
    }

    sort(n.begin(), n.end());

    for (auto a : n) {
        for (auto b : list) {
            if (a.first < b.second) {
                a.first = b.second;
                break;
            }
        }
        int len = a.second - a.first;
        if (len < 0) continue;
        num = len % L == 0 ? (len / L) : (len / L) + 1;
        list.push_back(make_pair(a.first, a.first + num * L));
        ans += num;
    }

    cout << ans;
}