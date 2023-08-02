#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ranking {
    int num;
    int first;
    int second;
    int third;
};

int N, K, n, a, b, c, tmp = 0;

vector<ranking> nation;
vector<int> ans(1001);

bool cmp(ranking& a, ranking& b) {
    if (a.first == b.first) {
        if (a.second == b.second) {
            return a.third > b.third;
        } else
            return a.second > b.second;
    } else
        return a.first > b.first;
}

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> n >> a >> b >> c;

        ranking r;
        r.num = n;
        r.first = a;
        r.second = b;
        r.third = c;
        nation.push_back(r);
    }

    sort(nation.begin(), nation.end(), cmp);

    ranking prev = nation[0];
    ans[nation[0].num] = 1;

    for (int i = 1; i < N; i++) {
        if (prev.first == nation[i].first && prev.second == nation[i].second && prev.third == nation[i].third) {
            ans[nation[i].num] = ans[prev.num];
            tmp++;
        } else {
            ans[nation[i].num] = ans[prev.num] + tmp + 1;
            tmp = 0;
        }
        prev = nation[i];
    }

    // for (auto a : nation) {
    //     cout << a.first << " " << a.second << " " << a.third <<" "<< a.num <<" " <<ans[a.num] << endl;
    // }

    cout << ans[K];
}
