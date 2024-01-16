#include <string>
#include <map>
#include <iostream>
using namespace std;

// U, D, R, L
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char cmd[4] = {'U', 'D', 'R', 'L'};
int reverse[4] = {1, 0, 3, 2};
map<char, int> m;
int visited[4][11][11];

int solution(string dirs) {
    int answer = 0;
    pair<int ,int> source;
    source.first = source.second = 5;
    for(int i = 0; i < 4; i++) m[cmd[i]] = i;
    for(auto d : dirs){
        int nextX = source.first + dir[m[d]].first;
        int nextY = source.second + dir[m[d]].second;
        if(nextY < 0 || nextX < 0 || nextY > 10 || nextX > 10) continue;
        if(!visited[m[d]][source.first][source.second]){
            answer++;
            visited[m[d]][source.first][source.second]++;
            visited[reverse[m[d]]][nextX][nextY]++;
        }
        source.first = nextX;
        source.second = nextY;
    }
    return answer;
}