#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<char> line;
vector<int> check;
map<char, int> m;
string character;
int a;

bool validation(vector<string>& data) {
    for (int i = 0; i < data.size(); i++) {
        int a, b, distance;
        for (int j = 0; j < 8; j++) {
            if (line[j] == data[i][0]) a = j;
            if (line[j] == data[i][2]) b = j;
        }
        distance = abs(a - b) - 1;
        if (data[i][3] == '=' && (data[i][4] - '0') != distance)
            return false;
        else if (data[i][3] == '<' && (data[i][4] - '0') <= distance)
            return false;
        else if (data[i][3] == '>' && (data[i][4] - '0') >= distance)
            return false;
    }
    return true;
}

void solution(vector<string>& data) {
    if (line.size() == 8 && validation(data)) {
        a++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (!check[i]) {
            check[i] = 1;
            line.push_back(m[i]);
            solution(data);
            check[i] = 0;
            line.pop_back();
        }
    }
}

int solution(int n, vector<string> data) {
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    line = vector<char>(0, 0);
    check = vector<int>(8, 0);
    m = map<char, int>();
    character = "ACFJMNRT";
    a = 0;

    int answer;
    for (int i = 0; i < 8; i++) {
        m[i] = character[i];
    }
    solution(data);
    answer = a;
    return answer;
}
