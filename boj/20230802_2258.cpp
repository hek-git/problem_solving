#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, w, p, ans = 0x7fffffff, flag;
vector<pair<int, int>> meat;
vector<int> cumWeight(100001);
vector<int> cumPrice(100001);

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first > b.first;
    else
        return a.second < b.second;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w >> p;
        meat.push_back(make_pair(w, p));
    }

    sort(meat.begin(), meat.end(), cmp);

    cumWeight[0] = meat[0].first;
    cumPrice[0] = meat[0].second;

    for (int i = 1; i < N; i++) {
        cumWeight[i] = cumWeight[i - 1] + meat[i].first;
        if (meat[i].second == meat[i - 1].second)
            cumPrice[i] = meat[i].second + cumPrice[i - 1];
        else
            cumPrice[i] = meat[i].second;
    }
    
    // for (int i = 0; i < N; i++) {
    //     cout << meat[i].first << " " << meat[i].second << " " << cumWeight[i] << " " << cumPrice[i] << endl;
    // }

    for (int i = 0; i < N; i++) {
        if (cumWeight[i] >= M) {
            ans = min(ans, cumPrice[i]);
            flag = 1;
        }
    }

    if (flag)
        cout << ans;
    else
        cout << -1;

    return 0;
}
