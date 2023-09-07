#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int t, n, a, b;
vector<pair<int, int>> store;
pair<int, int> source, dest;
set<pair<int, int>> visited;

int distance(pair<int, int> s, pair<int, int> d) { return (int)(abs(d.first - s.first) + abs(d.second - s.second)); }

bool is_visited(pair<int, int> s){
    if(visited.find(s) == visited.end()) return false;
    else return true;
}

bool bfs(pair<int, int> s, pair<int, int> d) {

    queue<pair<int, int>> q;
    q.push(s);

    while(!q.empty()){
        pair<int, int> source = q.front();
        q.pop();
        visited.insert(source);

        if(distance(source, d) <= 1000) return true;

        for(auto a : store){
            if(distance(source, a) <=1000 && !is_visited(a)){
                q.push(a);
            }
        }

    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> source.first >> source.second;
        store.clear();
        visited.clear();

        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            store.push_back(make_pair(a, b));
        }
        cin >> dest.first >> dest.second;
        sort(store.begin(), store.end());

        if (bfs(source, dest))
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}