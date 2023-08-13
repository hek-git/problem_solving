#include <iostream>
#include <string>

using namespace std;

int n, f[501], num;

int main() {
    cin >> n;
    f[0] = 0;

    for (int i = 1; i < 501; i++) {
        f[i] = f[i - 1];
        if (i % 5 == 0) {
            num = 0;
            int tmp = i;
            while (tmp % 5 == 0) {
				tmp/=5;
                num++;
            }
			f[i]+=num;
        }
    }
    cout << f[n];
}