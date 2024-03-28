#include <iostream>
#include <vector>
#include <algorithm>
#define INF 200000

using namespace std;

int N, S, n, lo, hi, answer = INF, sum[100001];
vector<int> list;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list.push_back(0);
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> n;
        sum[i] = sum[i - 1] + n;
        list.push_back(n);
    }

    lo = 1, hi = 1;
    while(lo <= hi && hi <= N){
        int tmp = sum[hi] - sum[lo - 1];
        if(tmp < S) hi++;
        else if(tmp > S) {
            answer = min(answer, hi - lo + 1);
            lo++;
        }
        else {
            answer = min(answer, hi - lo + 1);
            hi++, lo++;
        }
    }
    if(answer == INF) cout << 0;
    else cout << answer;
}