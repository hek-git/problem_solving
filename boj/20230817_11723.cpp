#include <iostream>
#include <string>

using namespace std;

int N, num, mask;
string cmd;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> cmd;

        if (!cmd.compare("add")) {
            //cout << "!";
            cin >> num;
            num = 1 << num-1;
            if (mask & num)
                continue;
            else
                mask += num;
            //cout << mask << '\n';
        } else if (!cmd.compare("remove")) {
            cin >> num;
            num = 1 << num-1;
            if (num & mask)
                mask -= num;
            else
                continue;
        } else if (!cmd.compare("check")) {
            cin >> num;
            num = 1 << num-1;
            if(num & mask) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (!cmd.compare("toggle")) {
            cin >> num;
            num = 1 << num-1;
            mask = mask ^ num;
        } else if (!cmd.compare("all")) {
            mask = 0b11111111111111111111;
        } else {
            mask = 0;
        }
    }
}