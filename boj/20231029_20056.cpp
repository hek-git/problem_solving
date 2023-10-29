#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Fireball class ����
class Fireball {
   public:
    int r;
    int c;
    int m;
    int s;
    int d;
    // ������ ����
    Fireball(int r = 0, int c = 0, int m = 0, int s = 0, int d = 0) {
        this->r = r;
        this->c = c;
        this->m = m;
        this->s = s;
        this->d = d;
    }
};

int N, M, K, r, c, m, s, d, odd, even, ans;
pair<int, int> dir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<Fireball> map;

// ���̾�� �̵���Ű�� �Լ� ��ⷯ �������� �̵� Ƚ�� ����ȭ
void moveFireball() {
    for (int k = 0; k < map.size(); k++) {
        s = map[k].s % N;
        map[k].r += dir[map[k].d].first * s;
        map[k].c += dir[map[k].d].second * s;
        if (map[k].r > N) map[k].r -= N;
        if (map[k].r < 1) map[k].r += N;
        if (map[k].c > N) map[k].c -= N;
        if (map[k].c < 1) map[k].c += N;
    }
}

// ������ ��ġ�� ���̾�� ��� Ȧ���̰ų� ��� ¦�� ������ ���ϴ��� Ȯ���ϴ� �Լ�
// ������ �����ϸ� true �ƴϸ� false
bool checkDir(vector<Fireball> fireBall) {
    int even = true;
    int odd = true;
    // �ϳ��� Ȧ���� ��� ¦���� �ƴ�
    for (auto f : fireBall)
        if (f.d % 2 != 0) even = false;
    // �ϳ��� ¦���� ��� Ȧ���� �ƴ�
    for (auto f : fireBall)
        if (f.d % 2 == 0) odd = false;
    return even || odd;
}

// 2�� �̻��� ���̾�� �ִ� ĭ�� ���� ���̾�� ��ġ�� �п� ��Ű�� �Լ�
vector<Fireball> seperateFireball(vector<Fireball>& fireBall) {
    vector<Fireball> f;
    int newR = fireBall[0].r;
    int newC = fireBall[0].c;
    int newM = 0;
    int newS = 0;
    int i = 1;
    pair<int, int> newD;
    for (int i = 0; i < fireBall.size(); i++) {
        newM += fireBall[i].m;
        newS += fireBall[i].s;
    }
    newM /= 5;
    newS /= fireBall.size();
    if (newM == 0) return f;
    // ������ ��� Ȧ���ų� ¦���� ������ 0, 2, 4, 8 �ƴ϶�� �ʱⰪ�� 1, 3, 5, 7
    if (checkDir(fireBall)) i = 0;
    for (; i < 8; i += 2) f.push_back(Fireball(newR, newC, newM, newS, i));
    return f;
}


// ��� ���̾�� ���� ������ ��ġ�� �ִ� ���̾�� �����ϰ�
// ������ �п��ϴ� �Լ��� �����Ͽ� �̸� ��ȯ��
vector<Fireball> seperateFireball() {
    vector<Fireball> ret;
    for (int i = 0; i < map.size(); i++) {
        // r, c�� ��� 0�̶�� �̹� ���� �� ���̾
        if (map[i].r == 0 && map[i].c == 0) continue;
        // ������ ��ġ�� ���̾�� ���� tmp
        vector<Fireball> tmp;
        tmp.push_back(map[i]);
        // r, c�� ��� ���ٸ� tmp�� �߰��ϰ� ���Ե� ���̾�� �ʱ�ȭ
        for (int j = i + 1; j < map.size(); j++) {
            if (map[i].r == map[j].r && map[i].c == map[j].c) {
                tmp.push_back(map[j]);
                map[j].r = map[j].c = 0;
            }
        }

        // ������ ��ġ�� ���̾�� 2�� �̻��ִٸ� �Լ� ���� �� ret �迭�� ��� ���� ����
        // �ϳ���� �ش� ���̾�� �״�� ret�� �߰�
        if (tmp.size() > 1) {
            tmp = seperateFireball(tmp);
            for (auto t : tmp) {
                ret.push_back(t);
            }
        } else
            ret.push_back(map[i]);
        map[i].r = map[i].c = 0;
    }
    return ret;
}

// K�� ��ŭ ���̾ �̵�, �п�
// �ݺ� ���� �� ���� ������ ����
void solve() {
    for (int i = 0; i < K; i++) {
        moveFireball();
        map = seperateFireball();
    }
    for (auto a : map) ans += a.m;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        map.push_back(Fireball(r, c, m, s, d));
    }
    solve();
    cout << ans;
}