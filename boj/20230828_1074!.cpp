#include <cmath>
#include <iostream>

using namespace std;

int N, r, c;

int solve(int n, int r, int c, int ans) {
    if (n == 0) return ans;
    int size = ((int)pow(2, n) - 1) / 2;
    int dPos = (int)pow(2, n - 1);
    int number = (int)pow(2, 2*n - 2);

    // 4사분면에 존재
    if (r > size && c > size) return solve(n - 1, r - dPos, c - dPos, ans + number * 3);
    // 3사분면에 존재
    else if (r > size && c <= size) return solve(n - 1, r - dPos, c, ans + number * 2);
    // 2사분면에 존재
    else if (r <= size && c > size) return solve(n - 1, r, c - dPos, ans + number * 1);
    // 1사분면에 존재
    else return solve(n - 1, r, c, ans + number * 0);
}

int main() {
    cin >> N >> r >> c;
    cout << solve(N, r, c, 0);
}