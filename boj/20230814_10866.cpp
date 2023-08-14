#include <iostream>
#include <string>

using namespace std;

int a[10001];
int n, num, front, rear, capacity;
string cmd;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (!cmd.compare("push_front")) {
            capacity++;
            cin >> num;
            a[front--] = num;
            if (front < 0) front = 10000;
        } else if (!cmd.compare("push_back")) {
            capacity++;
            cin >> num;
            rear = (rear + 1) % 10001;
            a[rear] = num;
        } else if (!cmd.compare("pop_front")) {
            if (!capacity)
                cout << -1 << '\n';
            else {
                front = (front + 1) % 10001;
                cout << a[front] << '\n';
                capacity--;
            }

        } else if (!cmd.compare("pop_back")) {
            if (!capacity)
                cout << -1 << '\n';
            else {
                cout << a[rear--] << '\n';
                if (rear < 0) rear = 10000;
                capacity--;
            }

        } else if (!cmd.compare("size")) {
            cout << capacity << '\n';
        } else if (!cmd.compare("empty")) {
            if (capacity)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        } else if (!cmd.compare("front")) {
            if (!capacity)
                cout << -1 << '\n';
            else
                cout << a[(front + 1) % 10001] << '\n';
        } else if (!cmd.compare("back")) {
            if (!capacity)
                cout << -1 << '\n';
            else
                cout << a[rear] << '\n';
        }
    }
}