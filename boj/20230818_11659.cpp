#include <iostream>
#include <vector>

using namespace std;

int N, M, s, d;
vector<int> v(100001);
vector<int> sum(100001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        sum[i] = v[i] + sum[i - 1];
    }

    for (int i = 1; i <= M; i++) {
        cin >> s >> d;
        cout << sum[d] - sum[s - 1] << '\n';
    }
}