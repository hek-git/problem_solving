#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, num, check[10001];
vector<int> number, ans;

void backTracking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check[number[i]]) {
            ans.push_back(number[i]);
            check[number[i]] = 1;
            backTracking(cnt + 1);
            ans.pop_back();
            check[number[i]] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    backTracking(0);
}