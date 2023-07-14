#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, num, p = -1;
    vector<int> stack;
    string command;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (!command.compare("push")) {
            cin >> num;
            stack.push_back(num);
            p++;
        } else if (!command.compare("pop")) {
            if (p == -1)
                cout << -1 << endl;
            else {
                cout << stack[p] << endl;
                stack.pop_back();
                p--;
            }
        } else if (!command.compare("size")) {
            cout << p + 1 << endl;
        } else if (!command.compare("empty")) {
            if (p == -1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (!command.compare("top")) {
            if (p == -1)
                cout << -1 << endl;
            else
                cout << stack[p] << endl;
        }
    }
}