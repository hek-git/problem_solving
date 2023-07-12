#include <iostream>
#include <string>

using namespace std;

int N;

int solve(string S, string T, int init) {
    int ans = init;

    for (int i = 1; i < N; i++) {
        if (i != N - 1) {
            if (S[i - 1] != T[i - 1]) {
                S[i] = S[i] == '0' ? '1' : '0';
                S[i - 1] = S[i - 1] == '0' ? '1' : '0';
                S[i + 1] = S[i + 1] == '0' ? '1' : '0';
                ans++;
            }
        } else {
            if (S[i] != T[i]) {
                S[i] = S[i] == '0' ? '1' : '0';
                S[i - 1] = S[i - 1] == '0' ? '1' : '0';
                ans++;
            }
        }
    }

    if (!S.compare(T))
        return ans;
    else
        return -1;
}

int main() {
    int a, b;
    string S, T;
    cin >> N >> S >> T;

    //첫번째 스위치를 안누르고 시작하는 경우
    a = solve(S, T, 0);

    //첫번째 스위치를 누르고 시작하는 경우
    S[0] = S[0] == '0' ? '1' : '0';
    S[1] = S[1] == '0' ? '1' : '0';
    b = solve(S, T, 1);

    if (a == -1 && b == -1)
        cout << -1;
    else if (a == -1 || b == -1)
        cout << max(a, b);
    else
        cout << min(a, b);
}