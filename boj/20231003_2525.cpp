#include <iostream>
#include <vector>

using namespace std;

int A, B, C, T, M, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    B = B + C;
    A = (B/60 + A) % 24;
    B = B%60;
    cout << A << " " << B;

}