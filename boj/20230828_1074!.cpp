#include <cmath>
#include <iostream>

using namespace std;

int N, r, c;

int solve(int n, int r, int c, int ans) {
    if (n == 0) return ans;
    int size = ((int)pow(2, n) - 1) / 2;
    int dPos = (int)pow(2, n - 1);
    int number = (int)pow(2, 2*n - 2);

    // 4��и鿡 ����
    if (r > size && c > size) return solve(n - 1, r - dPos, c - dPos, ans + number * 3);
    // 3��и鿡 ����
    else if (r > size && c <= size) return solve(n - 1, r - dPos, c, ans + number * 2);
    // 2��и鿡 ����
    else if (r <= size && c > size) return solve(n - 1, r, c - dPos, ans + number * 1);
    // 1��и鿡 ����
    else return solve(n - 1, r, c, ans + number * 0);
}

int main() {
    cin >> N >> r >> c;
    cout << solve(N, r, c, 0);
}