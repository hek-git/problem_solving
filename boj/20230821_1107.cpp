#include <cmath>
#include <iostream>

using namespace std;

int N, M, n, num[10], ans, m = 500000;

int digits(int n) {
    int digit = 0;
    if (n == 0) return 1;
    while (n != 0) {
        digit++;
        n /= 10;
    }
    return digit;
}

bool validate(int n) {
    if (n == 0) return !num[0];
    while (n != 0) {
        int tmp = n % 10;
        if (num[tmp]) return false;
        n /= 10;
    }
    return true;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> n;
        num[n] = 1;
    }

    ans = abs(100 - N);

    for (int i = 0; i <= 1000000; i++) {
        if (!validate(i)) continue;
        ans = min(ans, abs(N - i) + digits(i));
    }

    cout << ans;
}