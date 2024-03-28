#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, n;
vector<int> list;

int solve(){
    int  lo, hi, answer = 2000000001;
    lo = hi = 0;
    if(M == 0) return 0;
    while (hi < N) {
        int tmp_sum = abs(list[hi] - list[lo]);
        if (tmp_sum < M)
            hi++;
        else if(tmp_sum >= M){
            if(tmp_sum < answer) answer = tmp_sum;
            lo++;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> n;
        list.push_back(n);
    }
    sort(list.begin(), list.end());
    cout << solve();    
}