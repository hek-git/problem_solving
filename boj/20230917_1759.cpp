#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, C;
vector<char> alphabet, pwd;
char a, gather[5] = {'a', 'e', 'i', 'o', 'u'};

bool validate(vector<char>& pwd) {
    int g = 0, c = 0;
    for (int i = 0; i < pwd.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (pwd[i] == gather[j])
                g++;
        }
    }
    c = L - g;
    if (g >= 1 && c >= 2)
        return true;
    else
        return false;
}

void solve(int len, int idx) {
    if (len == L) {
        if (validate(pwd)) {
            for (int i = 0; i < len; i++) cout << pwd[i];
            cout << '\n';
        }
    }

    for (int i = idx; i < C; i++) {
        pwd.push_back(alphabet[i]);
        solve(len + 1, i + 1);
        pwd.pop_back();
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> a;
        alphabet.push_back(a);
    }
    sort(alphabet.begin(), alphabet.end());
    solve(0, 0);
}