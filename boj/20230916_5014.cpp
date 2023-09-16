#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D, visited[1000001], ans[1000001];
int INF = 1000001;

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int source = q.front();
        q.pop();

        if(source == G) break;
        if(source + U > F);
        else if(!visited[source+U]){
            visited[source+U] = 1;
            q.push(source+U);
            ans[source + U] = ans[source] + 1;
        }
        if(source - D < 1);
        else if(!visited[source - D]){
            visited[source - D] = 1;
            q.push(source-D);
            ans[source-D] = ans[source] + 1;
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;
    ans[S] = 1;
    bfs(S);
    if(ans[G] == 0) cout << "use the stairs";  
    else cout << ans[G] - 1;
}