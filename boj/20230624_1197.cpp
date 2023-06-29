#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {

public:
	int u, v, w;

	Edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}

	bool operator<(Edge e) {
		return this->w < e.w;
	}

};

class UnionFind {

	vector<int> parent;

public:
	UnionFind(int size) {
		for (int i = 0; i < size; i++) {
			parent.push_back(i);
		}
	}
	
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b) {
		parent[find(b)] = find(a);
	}

};

int main() {

	int n, m, u, v, w, ans = 0;
	vector<Edge> graph;
	vector<Edge> mst;
	UnionFind uf = UnionFind(100000);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph.push_back(Edge(u, v, w));
		//ans += w;
	}

	sort(graph.begin(), graph.end());


	for (Edge e : graph) {
		if (mst.size() == n + 1) break;
		if (uf.find(e.u) == uf.find(e.v)) continue;
		uf.merge(e.u, e.v);
		mst.push_back(e);
		ans += e.w;
	}

	/*for (int i = 0; i < mst.size(); i++) {
		printf("%d %d %d\n", mst[i].u, mst[i].v, mst[i].w);
	}*/
	printf("%d", ans);
	
}