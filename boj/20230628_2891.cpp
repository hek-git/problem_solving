#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, S, R, num, ans;
    vector<int> s(12, 0);
    vector<int> r;

    cin >> N >> S >> R;

    for (int i = 0; i < S; i++) {
        cin >> num;
        s[num] = 1;
    }

    for (int i = 0; i < R; i++) {
        cin >> num;
        r.push_back(num);
    }

    ans = S;

    for (int i = 0; i < R; i++) {
        if (r[i] && s[r[i]]) {
            ans--;
            s[r[i]] = 0;
            r[i] = 0;
        }
    }

    for (int i = 0; i < R; i++) {
        if (r[i] && s[r[i] - 1]) {
            ans--;
            s[r[i] - 1] = 0;
            r[i] = 0;
        } else if (r[i] && s[r[i] + 1]) {
            ans--;
            s[r[i] + 1] = 0;
            r[i] = 0;
        }
    }
    cout << ans;
}