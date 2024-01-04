#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

void swap(string& a, string& b){
    string tmp = a;
    a = b;
    b = tmp;
}

vector<string> solve(vector<string>& players, vector<string>& callings){
    vector<string> answer;
    for(int i = 0; i < players.size(); i++){
        m.insert({players[i], i});
    }
    for(int i = 0 ; i < callings.size(); i++){
        int n = m[callings[i]];
        m[players[n]]--;
        m[players[n-1]]++;
        swap(players[n], players[n-1]);
    }
    return players;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    return solve(players, callings);
}