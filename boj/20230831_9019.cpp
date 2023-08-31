#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int T, s, t, visited[10001];
string ans[10001];

int D(int num) {
    return 2 * num % 10000;
}

int S(int num) {
    if (!num)
        return 9999;
    else
        return num - 1;
}

int L(int num) {
    return num % 1000 * 10 + num / 1000;
}

int R(int num) {
    return num / 10 + num % 10 * 1000;
}

void initSettings() {
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i<=10000; i++) ans[i] = "";
}

void bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while(!q.empty()){
        int source = q.front();
        q.pop();
        
        if(source == t) return;

        if(!visited[D(source)]){
            ans[D(source)] = ans[source] + 'D';
            visited[D(source)] = 1;
            q.push(D(source));
        }
        if(!visited[S(source)]){
            ans[S(source)] = ans[source] +'S';
            visited[S(source)] = 1;
            q.push(S(source));
        }
        if(!visited[L(source)]){
            ans[L(source)] = ans[source] +'L';
            visited[L(source)] = 1;
            q.push(L(source));
        }
        if(!visited[R(source)]){
            ans[R(source)] = ans[source] +'R';
            visited[R(source)] = 1;
            q.push(R(source));
        }        
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s >> t;
        bfs(s, t);
        cout << ans[t] << "\n";
        initSettings();
    }
}