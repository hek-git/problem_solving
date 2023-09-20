#include <iostream>
#include <queue>

using namespace std;

int N;
char cmd, c;
deque<char> s, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        c = cin.get();
        if (c == '\n') break;
        s.push_back(c);
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (!s.empty()) {
                    tmp.push_back(s.back());
                    s.pop_back();
                }
                break;
            case 'D':
                if(!tmp.empty()){
                    s.push_back(tmp.back());
                    tmp.pop_back();
                }
                break;
            case 'B':
                if(!s.empty()) s.pop_back();
                break;
            case 'P':
                cin >> c;
                s.push_back(c);
                break;
        }
    }
    while(!tmp.empty()){
        s.push_back(tmp.back());
        tmp.pop_back();
    }
    while(!s.empty()){
        cout << s.front();
        s.pop_front();
    }
}