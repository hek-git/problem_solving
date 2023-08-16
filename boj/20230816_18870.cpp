#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, num, cnt, dup = 0;
vector<pair<int, int>> v(1000001), ans(1000001);

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        v[i] = make_pair(i, num);
    }

    sort(v.begin(), v.begin() + N, cmp);
    ans[0] = make_pair(0, v[0].first);

    for (int i = 1; i < N; i++) {
        if (v[i].second == v[i-1].second) dup++;
        ans[i] = make_pair(i - dup, v[i].first);
    }

    sort(ans.begin(), ans.begin() + N, cmp);

    for(int i =0; i<N; i++){
        printf("%d ", ans[i].first);
    }
}