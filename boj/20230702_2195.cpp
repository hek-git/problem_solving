#include <iostream>
#include <string>

using namespace std;

int main() {
    int i = 0, j = 0, ans = 0;
    string S, P;
    cin >> S >> P;

    while (i != P.size()) {
        while (j != S.size()) {
            if (P[i] == S[j])
                break;
            j++;
        }
        if (i != P.size() - 1 && j != S.size() - 1) {
            while (P[i] == S[j]) {
                i++, j++;
            }
        } else
            i++;
        cout << " ½ÇÇà " << i << " " << j << endl;
        j = 0, ans++;
    }
    cout << ans;
}