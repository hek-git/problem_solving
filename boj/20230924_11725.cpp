#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, u, v, Tree[100001];
vector<pair<int, int>> edge;
set<int> s;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        edge.push_back(make_pair(u, v));
    }
    sort(edge.begin(), edge.end(), cmp);

    for (int i = 0; i < N - 1; i++) {
        if(edge[i].second == 1){
            s.insert(edge[i].second);
            Tree[edge[i].first] = edge[i].second;
        }
    }
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> N;
//     for (int i = 0; i < N - 1; i++) {
//         cin >> u >> v;
//         if(v == 1){
//             Tree[u] = v;
//             s.insert(u);
//         }else{
//             if(s.find(v) != s.end()){
//                 Tree[u] = v;
//                 s.insert(u);
//             }
//             else Tree[v] = u;
//         }
//     }

//     for (int i = 2; i <= N; i++) {
//         cout << Tree[i] << '\n';
//     }
// }