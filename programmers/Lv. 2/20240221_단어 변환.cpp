#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int visited[52][52];
unordered_map<string, int> m;

int diff(string& a, string& b){
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) diff++;
    }
    return diff;
}

int bfs(string& begin, string& target, vector<string>& words) {
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    while(!q.empty()){
        pair<string, int> s = q.front();
        q.pop();
        
        if(!s.first.compare(target)) return s.second;
        for(int i = 0; i < words.size(); i++){
            if(visited[m[s.first]][m[words[i]]] || diff(s.first, words[i]) != 1) continue;
            q.push(make_pair(words[i], s.second + 1));
            visited[m[s.first]][m[words[i]]] = visited[m[words[i]]][m[s.first]] = 1;
        }
    }
    return 0;
}

bool check(string& target, vector<string>& words) {
    for (auto a : words) {
        if (!target.compare(a)) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    m[begin] = 0;
    for (int i = 1; i <= words.size(); i++) m[words[i - 1]] = i;
    if (check(target, words)) return 0;
    return bfs(begin, target, words);
}