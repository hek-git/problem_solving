
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, num, check[10001], cnt[10001];
vector<int> number, ans;

void solve(int len, int idx) {
    if (len == M) {
        for (int i = 0; i < M; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = idx; i < number.size(); i++) {
        if (cnt[number[i]] > 0) {
            cnt[number[i]]--;
            ans.push_back(number[i]);
            solve(len + 1, i);
            ans.pop_back();
            cnt[number[i]]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (!check[num]) {
            number.push_back(num);
            check[num] = 1;
        }
        cnt[num]++;
    }
    sort(number.begin(), number.end());
    solve(0, 0);
}