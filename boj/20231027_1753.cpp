#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;
int V, E, K, u, v, w, d[20001], visited[20001];
vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>> pq;

void initDistance(){
    // √ ±‚»≠
    for(int i = 1; i <= V; i++){
        if(i == K) d[i] = 0;
        else d[i] = INF;
    }
    for(int i = 0; i < graph[K].size(); i++) d[graph[K][i].first] = min(d[graph[K][i].first], graph[K][i].second);
}

void dijkstra(int start){
    pq.push(make_pair(0, K));
    while(!pq.empty()){
        int index = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        for(int j = 0; j < graph[index].size(); j++){
            pair<int, int> next = graph[index][j];
            if(d[next.first] >= weight + next.second){
                d[next.first] = weight + next.second;
                pq.push(make_pair(-d[next.first], next.first));
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    initDistance();
    dijkstra(K);
    for(int i = 1 ; i <= V; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}