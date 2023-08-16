#include <iostream>
#define MOD 1234567891

using namespace std;

long long N, r = 1, ans;
char c;

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> c;
        ans = (ans + ((c - 'a' + 1) * r) % MOD) % MOD;
        r = r * 31 % MOD;
    }

    cout << ans;
}