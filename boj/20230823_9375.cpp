#include <iostream>
#include <map>
#include <string>

using namespace std;

int T, n, ans;
string category, cloth;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        ans = 1;
        map<string, int> m;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> cloth >> category;

            if (m.find(category) == m.end()) {
                m[category] = 1;
            } else
                m[category]++;
        }

        for (auto a : m) {
            ans = ans * (a.second + 1);
        }
        cout << ans - 1 << endl;
    }
}