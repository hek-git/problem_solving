#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// edge class ����
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

// unionFind�� unionRank ���� �ʱ�ȭ
void makeSet(int x) {
    for (int i = 0; i < x; i++) {
        unionFind[i] = i;
        unionRank[i] = 0;
    }
}

// x�� ���� ��ȣ�� ã�� �Լ�
int find(int x) {
    // ���� ��ȣ�� �ڽ��� ��� ��ȣ�� ���ٸ� �θ� ����̹Ƿ� ���� ��ȣ ��ȯ
    if (unionFind[x] == x)
        return x;
    // ���� ��ȣ�� ��� ��ȣ�� �ٸ��ٸ� ��͸� �̿��Ͽ� �ڽ��� �θ��� ���� ��ȣ Ž��
    // ��� ���� ����ȭ�� �����Ͽ� find �ϸ鼭 ���� ��� ���� �θ� ��带 ��� ���� ��ȣ�� �����Ѵ�.
    else{
        unionFind[x] = find(unionFind[x]);
        return unionFind[x];
    }
}

// x�� y������ ����(������ ����)�ϴ� �Լ�
void merge(int x, int y) {
    // x�� y�� ���� ��ȣ(�θ� ���)�� ���� ã�´�.
    int X = find(x);
    int Y = find(y);
    // union-by-rank ����ȭ �����Ѵ�.
    // �׻� ���̰� �� ���� Ʈ���� ���̰� ���� Ʈ�� �ؿ� �ִ´�. ��, ���̰� �� ���� ���� ���չ�ȣ�� ����
    if(unionRank[X] < unionRank[Y]) unionFind[X] = Y;
    else {
        unionFind[Y] = X;
        // ���̰� ���ٸ� ��ģ �� (x�� ���� +1)
        if(unionRank[X] == unionRank[Y]) unionRank[X]++;
    }
}

// edge ���Լ�
bool cmp(edge& a, edge& b) { return a.w < b.w; }

void solve() {
    // ���� �ʱ�ȭ
    makeSet(10001);
    for (int i = 0; i < graph.size(); i++) {
        // mst�� ���� ������ V - 1�̸� Ʈ�� �ϼ��̹Ƿ� break�Ͽ� �˰��� ����
        if (mst.size() == (V - 1)) break;
        // ������ ����� �� ����� ���� ��ȣ�� �ٸ���
        if (find(graph[i].u) != find(graph[i].v)){
            // �� ��� ����(������ ����), mst�� ���� �߰�
            merge(graph[i].u, graph[i].v);
            mst.push_back(graph[i]);
        }
    }
    // mst�� �������� ����ġ�� ��� ����
    for (auto a : mst) ans += a.w;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        graph.push_back(edge(A, B, C));
    }
    // ������ ����ġ�� ������������ ����
    sort(graph.begin(), graph.end(), cmp);
    solve();
    cout << ans;
}