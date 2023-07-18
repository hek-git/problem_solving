#include <iostream>
using namespace std;

int N, dir, a, b, cnt, num;

int main() {
    cin >> N;

    a = b = cnt = dir = 1;

    while (cnt < N) {
        for (int i = 0; i < num; i++) {
            if (!dir)
                a++, b--;
            else
                a--, b++;
            cnt++;

            if (cnt >= N) break;
        }
        
        if (cnt < N) {
            if (dir)
                b++;
            else
                a++;
        }
        dir = !dir;
        cnt++;
        num++;
    }

    cout << a << "/" << b;
}