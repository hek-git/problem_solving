#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// edge class 선언
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

int V, E, A, B, C, unionFind[10001], unionRank[10001], ans;
vector<edge> graph, mst;

// unionFind와 unionRank 각각 초기화
void makeSet(int x) {
    for (int i = 0; i < x; i++) {
        unionFind[i] = i;
        unionRank[i] = 0;
    }
}

// x의 집합 번호를 찾는 함수
int find(int x) {
    // 집합 번호와 자신의 노드 번호가 같다면 부모 노드이므로 집합 번호 반환
    if (unionFind[x] == x)
        return x;
    // 집합 번호와 노드 번호가 다르다면 재귀를 이용하여 자신의 부모의 집합 번호 탐색
    // 경로 압축 최적화를 적용하여 find 하면서 만난 모든 값의 부모 노드를 모두 집합 번호로 수정한다.
    else{
        unionFind[x] = find(unionFind[x]);
        return unionFind[x];
    }
}

// x와 y집합을 병합(합집합 연산)하는 함수
void merge(int x, int y) {
    // x와 y의 집합 번호(부모 노드)를 각각 찾는다.
    int X = find(x);
    int Y = find(y);
    // union-by-rank 최적화 적용한다.
    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉, 높이가 더 높은 쪽의 집합번호를 취함
    if(unionRank[X] < unionRank[Y]) unionFind[X] = Y;
    else {
        unionFind[Y] = X;
        // 높이가 같다면 합친 후 (x의 높이 +1)
        if(unionRank[X] == unionRank[Y]) unionRank[X]++;
    }
}

// edge 비교함수
bool cmp(edge& a, edge& b) { return a.w < b.w; }

void solve() {
    // 집합 초기화
    makeSet(10001);
    for (int i = 0; i < graph.size(); i++) {
        // mst의 에지 개수가 V - 1이면 트리 완성이므로 break하여 알고리즘 종료
        if (mst.size() == (V - 1)) break;
        // 에지에 연결된 두 노드의 집합 번호가 다를때
        if (find(graph[i].u) != find(graph[i].v)){
            // 두 노드 병합(합집합 연산), mst에 에지 추가
            merge(graph[i].u, graph[i].v);
            mst.push_back(graph[i]);
        }
    }
    // mst의 에지들의 가중치를 모두 더함
    for (auto a : mst) ans += a.w;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        graph.push_back(edge(A, B, C));
    }
    // 에지의 가중치의 오름차순으로 정렬
    sort(graph.begin(), graph.end(), cmp);
    solve();
    cout << ans;
}