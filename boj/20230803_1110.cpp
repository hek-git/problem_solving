#include <iostream>

using namespace std;

int N, n, ans, second;

int main() {
    cin >> N;
    n = N;
    do {
        second = n % 10;
        n = (second + n / 10) % 10 + second * 10;
        ans++;
    } while (n != N);

    cout << ans;
}
