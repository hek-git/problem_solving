#include <cstdio>
#include <vector>

using namespace std;

int N, n;
vector<int> v(10001, 0);

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        v[n]++;
    }

    for (int i = 1; i <= 10001; i++) {
        for (int j = 0; j < v[i]; j++) {
            printf("%d\n", i);
        }
    }
}