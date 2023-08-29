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

// �� MBTI ������ �Ÿ��� ���ϴ� �Լ�
int distance(string& a, string& b, string& c) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) d++;
        if (a[i] != c[i]) d++;
        if (b[i] != c[i]) d++;
    }
    return d;
}

// 3 �� for���� �̿��Ͽ� ��� ����� ���� �� ���ϰ� �ּҰ��� �����Ѵ�.
// ans�� ����� ū ���� 10���� ����
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
        // �� ���̽����� map, vector �ʱ�ȭ
        cin >> N;
        m.clear();
        v.clear();

        if (N > 32) {
            cin.ignore();
            cin.ignore(500000, '\n');
            cout << 0 << '\n';
            continue;
        }

        // mbti�� �Է¹ް� map���� ��ȸ�� �� 3 �̻��̸�
        // ��� �ݺ��� Ż�� �� solve �Լ� ����
        // �̿��� ��� map�� �߰� �� ���� �� solve �Լ� ���� 
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