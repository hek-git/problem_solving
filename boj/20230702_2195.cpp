#include <iostream>
#include <string>

using namespace std;

int main() {
    int i = 0, j = 0, cnt = 0, ans = 0;
    string S, P;
    cin >> S >> P;

    while (i != P.size()) {
        cnt = 1;
        while (j != S.size()) {
            if (P[i] == S[j] && i != P.size() - 1 && j != S.size() - 1) {
                int tmp_i = i, tmp_j = j, tmp_cnt = 0;
                while (P[tmp_i] == S[tmp_j] && tmp_i != P.size() && tmp_j != S.size()) {
                    tmp_i++, tmp_j++, tmp_cnt++;
                }
                if (cnt < tmp_cnt) {
                    cnt = tmp_cnt;
                }
            }
            j++;
        }
        i += cnt, j = 0, ans++;
    }
    cout << ans;
}