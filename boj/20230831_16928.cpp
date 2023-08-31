#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ladder[101], snake[101], ans[101];

void initAns(){
    for(int i = 2; i<=100; i++) ans[i] = 100;    
}

void bfs(){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int source = q.front();
        q.pop();
        
        for(int i = 1; i<=6; i++){
            int dest = source + i;
            if(dest > 100) break;
            
            if(ladder[dest]) dest = ladder[dest];        
            if(snake[dest]) dest = snake[dest];

            if(ans[dest] > ans[source]+1) {
                ans[dest] = ans[source] + 1;
                q.push(dest);
            }
        }
    }
}

int main() {
    
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
    initAns();
    bfs();
    cout << ans[100];
}