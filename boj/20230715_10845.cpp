#include <iostream>
#include <string>

using namespace std;

int queue[10001], N, num, capacity, front, back;
string command;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (!command.compare("push")) {
            cin >> num;
            capacity++;
            queue[back++] = num;
        } else if (!command.compare("pop")) {
            if (!capacity)
                cout << -1 << endl;
            else {
                capacity--;
                cout << queue[front++] << endl;
            }
        } else if (!command.compare("size")) {
            cout << capacity << endl;
        } else if (!command.compare("empty")) {
            if (capacity)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else if (!command.compare("front")) {
            if (!capacity)
                cout << -1 << endl;
            else
                cout << queue[front] << endl;
        } else if (!command.compare("back")) {
            if (!capacity)
                cout << -1 << endl;
            else
                cout << queue[back - 1] << endl;
        }
    }
}
