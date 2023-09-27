#include <iostream>
#include <vector>

using namespace std;

int N, s, t, ans[100001], visited[100001];
vector<int> list[100001];

void dfs(int s){
    visited[s] = 1;
    for(int i = 0; i<list[s].size(); i++){
        if(!visited[list[s][i]]){
            ans[list[s][i]] = s;
            dfs(list[s][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i<N; i++){
        cin >> s >> t;
        list[s].push_back(t);
        list[t].push_back(s);
    }

    dfs(1);
    for(int i = 2; i<=N; i++){
        cout << ans[i] << '\n';
    }
    

}