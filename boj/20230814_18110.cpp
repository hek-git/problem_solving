#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, num, aver, a;
double s;
vector<int> v;

int main() {
    
    scanf("%d", &n);

    if(!n){
        printf("0");
        return 0;
    }

    aver = (int)((double)n * 0.15 + 0.5);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    for (int i = aver; i < n - aver; i++) {
        s += v[i];
    }

    a = s / (double)(n - aver * 2) + 0.5;
    printf("%d", a);
}