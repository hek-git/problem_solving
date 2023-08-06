#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N, ans, a, b;

int solution(vector<pair<int, int>>& candidate){

    int cmp = candidate[0].second;

    for(int i=1; i<N; i++){
        if(candidate[i].second > cmp) continue;
        else{
            cmp = candidate[i].second;
            ans++;
        }
    }
    return ans;
}

int main() {
    cin >> T;
    for(int i=0; i<T; i++){
        vector<pair<int, int>> candidate;
        cin >> N;
        ans = 1;

        for(int j=0; j<N; j++){
            cin >> a >> b;
            candidate.push_back(make_pair(a, b));
        }

        sort(candidate.begin(), candidate.end());

        // cout << "Ãâ·Â" << endl;
        // for(int i=0; i<N; i++){
        //     cout << candidate[i].first << " " <<candidate[i].second << endl;
        // }
        // cout << endl;

        cout << solution(candidate) << endl;
    }
}