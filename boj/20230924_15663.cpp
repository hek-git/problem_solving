#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, num, check[10001], cnt[10001];
vector<int> number, ans;
vector<vector<int>> list;

// 수열의 중복 검사를 통한 풀이
// bool validate(vector<int>& a) {
//     for (int i = 0; i < list.size(); i++) {
//         int cnt = 0;
//         for (int j = 0; j < list[i].size(); j++) {
//             if (a[j] == list[i][j]) cnt++;
//             else break;
//         }
//         if (cnt == a.size()) return false;
//     }
//     return true;
// }

// 조건을 이용한 백트래킹 풀이
void solve(int len) {
    if (len == M) {
        for (int i = 0; i < M; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 0; i < number.size(); i++) {
        if (cnt[number[i]] > 0) {
            cnt[number[i]]--;
            ans.push_back(number[i]);
            solve(len + 1);
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
        if (!check[num]) number.push_back(num);
        check[num] = 1;
        cnt[num]++;
    }
    sort(number.begin(), number.end());
    solve(0);
}
