#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int T, N;
map<string, int> m;
vector<string> v;
string mbti;

// 세 MBTI 사이의 거리를 구하는 함수
int distance(string& a, string& b, string& c) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) d++;
        if (a[i] != c[i]) d++;
        if (b[i] != c[i]) d++;
    }
    return d;
}

// 3 중 for문을 이용하여 모든 경우의 수를 다 구하고 최소값을 갱신한다.
// ans는 충분히 큰 값인 10으로 설정
int solve(vector<string>& v) {
    int ans = 10;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                ans = min(ans, distance(v[i], v[j], v[k]));
            }
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        // 매 케이스마다 map, vector 초기화
        cin >> N;
        m.clear();
        v.clear();

        if (N > 32) {
            cin.ignore();
            cin.ignore(500000, '\n');
            cout << 0 << '\n';
            continue;
        }

        // mbti를 입력받고 map에서 조회한 뒤 3 이상이면
        // 즉시 반복문 탈출 후 solve 함수 실행
        // 이외의 경우 map값 추가 및 갱신 후 solve 함수 실행 
        for (int j = 0; j < N; j++) {
            cin >> mbti;
            if (m.find(mbti) != m.end() && m[mbti] >= 3)
                continue;
            else if (m.find(mbti) != m.end() && m[mbti] < 3)
                m[mbti]++;
            else if (m.find(mbti) == m.end())
                m[mbti] = 1;
            v.push_back(mbti);
        }
        cout << solve(v) << '\n';
    }
}