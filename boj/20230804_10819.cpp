#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, num, ans;
vector<int> v;

int f(vector<int> v) {
    int n = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        n += abs(v[i] - v[i+1]);
    }
    return n;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    do {
        ans = max(ans, f(v));
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;
}