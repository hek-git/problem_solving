#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, check[10];
char a;
vector<int> number;
vector<char> op;
vector<string> candidate;

bool validate(vector<int>& number) {
    for (int i = 0; i < N; i++) {
        if (op[i] == '>') {
            if (number[i] <= number[i + 1]) return false;
        } else {
            if (number[i] >= number[i + 1]) return false;
        }
    }
    return true;
}

string makeString(vector<int>& number) {
    string s;
    for (int i = 0; i < number.size(); i++) s += number[i] + '0';
    return s;
}

void solve(int len) {
    if (len == N + 1) {
        if (validate(number)) {
            candidate.push_back(makeString(number));
        }
    }

    for (int i = 0; i < 10; i++) {
        if(!check[list[i]]){
            check[list[i]] = 1;
            number.push_back(list[i]);
            solve(len + 1);
            check[list[i]] = 0;
            number.pop_back();
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        op.push_back(a);
    }
    solve(0);
    sort(candidate.begin(), candidate.end());
    cout << candidate[candidate.size() - 1] << endl << candidate[0];
}