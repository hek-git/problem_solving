#include <iostream>
#include <string>

using namespace std;

string S;
int N, M, flag, ans, cnt;
bool persist;#include <iostream>
#include <unordered_set>

using namespace std;

int T, M, N, x, y;

// Brute-force 알고리즘(시간 초과) 
//int solve(int M, int N, int x, int y) {
//    int ans = 1;
//    int dx = 1, dy = 1;
//    while (dx != M || dy != N) {
//        if (dx == x && dy == y) return ans;
//        
//        if (dx >= M) dx = 1;
//        else dx++;
//
//        if (dy >= N) dy = 1;
//        else dy++;
//        
//        ans++;
//    }
//    if (dx == x && dy == y) return ans;
//    return -1;
//}

int gcd(int a, int b) {
    if (b == 0) return a;
    if (a < b) return gcd(b, a);
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int solve(int M, int N, int x, int y) {
    unordered_set<int> s;
    int num = lcm(M, N);
    for (int i = 0; M*i + x <= num; i++) {
        s.insert(M * i + x);
    }

    for (int i = 0; N*i + y <= num; i++) {
        if(s.find(N * i + y) != s.end()) return N * i + y;
    }

    return -1;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        if (M < N) {
            swap(M, N);
            swap(x, y);
        }
        cout << solve(M, N, x, y) << '\n';
    }
}

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