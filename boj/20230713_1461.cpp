#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, num, ans = 0, m = 0;
    deque<int> total, left, right;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (abs(num) > abs(m)) m = num;

        total.push_back(num);
        if (num < 0)
            left.push_back(num);
        else
            right.push_back(num);
    }

    sort(right.begin(), right.end());
    sort(left.begin(), left.end());

    if (M >= N) {
        if (m < 0) {
            if (right.empty())
                ans += -left.front();
            else {
                ans += -left.front();
                ans += right.back() * 2;
            }
        } else {
            if (left.empty())
                ans += right.front();
            else {
                ans += right.back();
                ans += -left.front() * 2;
            }
        }
        cout << ans;
        return 0;
    }

    if (m < 0) {
        ans += -left.front();

        if (M <= left.size()) {
            for (int i = 0; i < M; i++) {
                left.pop_front();
            }
        } else {
            while (!left.empty()) left.pop_front();
        }

    } else if (m > 0 && M <= right.size()) {
        ans += right.back();
        if (M <= right.size()) {
            for (int i = 0; i < M; i++) {
                right.pop_back();
            }
        } else {
            while (!right.empty()) right.pop_back();
        }
    }

    while (M <= left.size()) {
        ans += -left.front() * 2;
        for (int i = 0; i < M; i++) {
            left.pop_front();
        }
    }

    while (M <= right.size()) {
        ans += right.back() * 2;
        for (int i = 0; i < M; i++) {
            right.pop_back();
        }
    }

    if (!left.empty()) ans += -left.front() * 2;
    if (!right.empty()) ans += right.back() * 2;

    cout << ans;
    return 0;
}
