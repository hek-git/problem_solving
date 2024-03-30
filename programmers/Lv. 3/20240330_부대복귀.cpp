#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(vector<int> graph[], int source, int destination){
    int time = -1, visited[100001] = {0, };
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(s == destination){
            time = visited[destination];
            break;
        }
        for(int i = 0; i < graph[s].size(); i++){
            int next = graph[s][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = visited[s] + 1;
            }
        }
    }

    return time;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> graph[100001];
    for(int i = 0; i < roads.size(); i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);        
    }

    for(int i = 0; i < sources.size(); i++) answer.push_back(bfs(graph, sources[i], destination));
    return answer;
}