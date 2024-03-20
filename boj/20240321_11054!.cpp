#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n, dp_increase[1001], dp_decrease[1001], answer = 1;
vector<int> list;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        list.push_back(n);
        dp_increase[i] = dp_decrease[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (list[i] > list[j]) {
                dp_increase[i] = max(dp_increase[i], dp_increase[j] + 1);
            }
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (list[i] > list[j]) {
                dp_decrease[i] = max(dp_decrease[i], dp_decrease[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(list[i] == list[j]) answer = max(answer, dp_increase[i] + dp_decrease[j] - 1);
            else answer = max(answer, dp_increase[i] + dp_decrease[j]);
        }
    }
    cout << answer;
}