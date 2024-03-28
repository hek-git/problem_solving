#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n, lo, hi, sum = 2000000001;
vector<int> list;
pair<int, int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        list.push_back(n);
    }

    lo = 0, hi = N - 1;
    while(lo < hi){
        int tmp_sum = list[hi] + list[lo];
        if((hi != lo) && abs(tmp_sum) < sum){
            sum = abs(tmp_sum);
            answer.first = list[lo];
            answer.second = list[hi];
        }
        if(tmp_sum >= 0) hi--;
        else lo++;
    }
    cout << answer.first << " " << answer.second;
}