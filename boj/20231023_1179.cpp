#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class edge {
   public:
    int u;
    int v;
    int w;
    edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int V, E, A, B, C, unionFind[10001], ans;
vector<edge> graph, mst;

void init() {
    for (int i = 0; i < 10001; i++) {
        unionFind[i] = i;
    }
}

int find(int a) {
    if (unionFind[a] == a)
        return a;
    else{
        unionFind[a] = find(unionFind[a]);
        return unionFind[a];
    }
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);
    unionFind[B] = A;
}

bool cmp(edge& a, edge& b) { return a.w < b.w; }

void solve() {
    init();
    for (int i = 0; i < graph.size(); i++) {
        if (mst.size() == (V - 1)) break;
        if (find(graph[i].u) == find(graph[i].v))
            continue;
        else {
            merge(graph[i].u, graph[i].v);
            mst.push_back(graph[i]);
        }
    }
    for (auto a : mst) ans += a.w;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        graph.push_back(edge(A, B, C));
    }
    sort(graph.begin(), graph.end(), cmp);
    solve();
    cout << ans;
}