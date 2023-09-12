#include <iostream>
#include <vector>

using namespace std;

int N, M, check[9];
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
        if(check[i] == 0){
            check[i] = 1;
            ans.push_back(number[i]);
            backTracking(cnt + 1);
            ans.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        number.push_back(i);
    }
    backTracking(0);
}