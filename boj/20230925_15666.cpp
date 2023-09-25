#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, num, check[10001], cnt[10001];
vector<int> number, ans;
vector<vector<int>> list;

bool validate(vector<int>& a) {
    for (int i = 0; i < list.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < list[i].size(); j++) {
            if (a[j] == list[i][j])
                cnt++;
            else
                break;
        }
        if (cnt == a.size()) return false;
    }
    return true;
}

// ������ �ߺ� �˻縦 ���� Ǯ��
void solve(int len, int idx) {
    if (len == M) {
        if (validate(ans)) {
            for (int i = 0; i < M; i++) cout << ans[i] << " ";
            cout << '\n';
            list.push_back(ans);
        }
        return;
    }
    for (int i = idx; i < number.size(); i++) {
        ans.push_back(number[i]);
        solve(len + 1, i);
        ans.pop_back();
    }
}

// ������ �̿��� ��Ʈ��ŷ Ǯ��
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> N >> M;
//     for (int i = 0; i < N; i++) {
//         cin >> num;
//         if (!check[num]) number.push_back(num);
//         check[num] = 1;
//         cnt[num]++;
//     }
//     for(auto a : number) cnt[a] += M;

//     sort(number.begin(), number.end());
//     solve(0, 0);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num;
        number.push_back(num);
    }

    sort(number.begin(), number.end());
    solve(0, 0);
}