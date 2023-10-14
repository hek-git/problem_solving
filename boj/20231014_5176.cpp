#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, P, M, seat[501], n, ans;

void init() {
    for (int i = 0; i < 501; i++) seat[i] = 0;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> P >> M;
        ans = 0;
        init();
        for (int j = 0; j < P; j++) {
            cin >> n;
            if (seat[n])
                ans++;
            else
                seat[n] = 1;
        }
        cout << ans << endl;
    }
}