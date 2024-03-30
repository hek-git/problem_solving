#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, n, pointer[1001], answer = 1000000001;
vector<vector<int>> school;

void solve(){
    while(true){
        int min_i , min_n = 1000000001, max_n = -1;
        for(int i = 0; i < N; i++){
            if(min_n > school[i][pointer[i]]){
                min_n = school[i][pointer[i]];
                min_i = i;
            }
            max_n = max(max_n, school[i][pointer[i]]);
        }
        answer = min(answer, max_n - min_n);
        if(pointer[min_i] == M - 1) break;
        else pointer[min_i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        for(int j = 0; j < M; j++){
            cin >> n;
            tmp.push_back(n);
        }
        school.push_back(tmp);
    }

    for(int i = 0; i < N; i++) sort(school[i].begin(), school[i].end());
    solve();
    cout << answer;
}