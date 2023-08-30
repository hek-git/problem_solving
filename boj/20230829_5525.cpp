#include <iostream>
#include <string>

using namespace std;

string S;
int N, M, flag, ans, cnt;
bool persist;

int main() {
    cin >> N >> M >> S;

    for (int i = 0; i < M; i++) {
        if (S[i] == 'I' && flag == 0) {
            flag = 1;
            cnt++;
            if (persist) ans++;
            if (cnt == N + 1) {
                ans++;
                persist = true;
            }
        } else if (S[i] == 'O' && flag == 1) {
            flag = 0;
        } else {
			flag = 1;
			cnt = 0;
			if(S[i] == 'I') cnt++;
			if(S[i] == 'O') flag = 0;
            persist = false;
        }
    }
    cout << ans;
}