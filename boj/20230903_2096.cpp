#include <iostream>
#include <algorithm>

using namespace std;

int N, max_dp[3], min_dp[3], input[3];

void maxPoint(int* point) {

    int cpy_dp[3] = { max_dp[0], max_dp[1], max_dp[2] };
    max_dp[0] = max(cpy_dp[0], cpy_dp[1]) + point[0];
    max_dp[1] = max({ cpy_dp[0], cpy_dp[1], cpy_dp[2] }) + point[1];
    max_dp[2] = max(cpy_dp[1], cpy_dp[2]) + point[2];

}

void minPoint(int* point) {

    int cpy_dp[3] = { min_dp[0], min_dp[1], min_dp[2] };
    min_dp[0] = min(cpy_dp[0], cpy_dp[1]) + point[0];
    min_dp[1] = min({ cpy_dp[0], cpy_dp[1], cpy_dp[2] }) + point[1];
    min_dp[2] = min(cpy_dp[1], cpy_dp[2]) + point[2];

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> input[j];
        }
        if (i == 1) {
            min_dp[0] = max_dp[0] = input[0];
            min_dp[1] = max_dp[1] = input[1];
            min_dp[2] = max_dp[2] = input[2];
        }
        else {
            maxPoint(input);
            minPoint(input);
        }
    }

    cout << max({ max_dp[0], max_dp[1], max_dp[2] }) << " " << min({ min_dp[0], min_dp[1], min_dp[2] });

}