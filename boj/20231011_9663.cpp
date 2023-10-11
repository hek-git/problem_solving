#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, ans, check[15];
vector<pair<int, int>> queen;

bool validate(vector<pair<int, int>>& queen, pair<int, int>& p) {
    int x = p.second;
    int y = p.first;
    if (y == 0) return true;
    if(check[x]) return false;
    for (int i = 0; i < queen.size(); i++) {
        int queenX = queen[i].second;
        int queenY = queen[i].first;
        if((queenY - y == queenX - x) || (queenY - y == -(queenX - x))) return false;
    }
    return true;
}

void solve(int r) {
    if (queen.size() == N) {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++) {
        pair<int, int> p = make_pair(r, i);
        if (validate(queen, p)) {
            queen.push_back(p);
            check[i] = 1;
            solve(r + 1);
            check[i] = 0;
            queen.pop_back();
        }
    }
}

int main() {
    cin >> N;
    solve(0);
    cout << ans;
}
