#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Fireball class 선언
class Fireball {
   public:
    int r;
    int c;
    int m;
    int s;
    int d;
    // 생성자 선언
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

// 파이어볼을 이동시키는 함수 모듈러 연산으로 이동 횟수 최적화
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

// 동일한 위치의 파이어볼이 모두 홀수이거나 모두 짝수 방향을 향하는지 확인하는 함수
// 조건을 만족하면 true 아니면 false
bool checkDir(vector<Fireball> fireBall) {
    int even = true;
    int odd = true;
    // 하나라도 홀수면 모두 짝수는 아님
    for (auto f : fireBall)
        if (f.d % 2 != 0) even = false;
    // 하나라도 짝수면 모두 홀수는 아님
    for (auto f : fireBall)
        if (f.d % 2 == 0) odd = false;
    return even || odd;
}

// 2개 이상의 파이어볼이 있는 칸에 대해 파이어볼을 합치고 분열 시키는 함수
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
    // 방향이 모두 홀수거나 짝수면 방향은 0, 2, 4, 8 아니라면 초기값인 1, 3, 5, 7
    if (checkDir(fireBall)) i = 0;
    for (; i < 8; i += 2) f.push_back(Fireball(newR, newC, newM, newS, i));
    return f;
}


// 모든 파이어볼에 대해 동일한 위치에 있는 파이어볼을 종합하고
// 실제로 분열하는 함수를 실행하여 이를 반환함
vector<Fireball> seperateFireball() {
    vector<Fireball> ret;
    for (int i = 0; i < map.size(); i++) {
        // r, c가 모두 0이라면 이미 종합 된 파이어볼
        if (map[i].r == 0 && map[i].c == 0) continue;
        // 동일한 위치의 파이어볼을 가질 tmp
        vector<Fireball> tmp;
        tmp.push_back(map[i]);
        // r, c가 모두 같다면 tmp에 추가하고 포함된 파이어볼은 초기화
        for (int j = i + 1; j < map.size(); j++) {
            if (map[i].r == map[j].r && map[i].c == map[j].c) {
                tmp.push_back(map[j]);
                map[j].r = map[j].c = 0;
            }
        }

        // 동일한 위치의 파이어볼이 2개 이상있다면 함수 실행 후 ret 배열로 모든 원소 복사
        // 하나라면 해당 파이어볼을 그대로 ret에 추가
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

// K번 만큼 파이어볼 이동, 분열
// 반복 종료 후 질량 총합을 구함
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