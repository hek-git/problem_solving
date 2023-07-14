#include <iostream>

using namespace std;

int N, num, a, b, fibo[41][2];

int main() {

    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cout << fibo[num][0] << " " << fibo[num][1] << endl;
    }
}