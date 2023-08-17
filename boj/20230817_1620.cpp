#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
string s;
map<string, int> num;
map<int, string> name;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> s;
        name[i] = s;
        num[s] = i;
    }

    for (int i = 1; i <= M; i++) {
        cin >> s;
        try {
            cout << name[stoi(s)] << '\n';
        } catch (exception e) {
            cout << num[s] << '\n';
        }
    }
}