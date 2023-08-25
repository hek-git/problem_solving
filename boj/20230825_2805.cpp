#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long N, M, num;
long long l = 0, r = 2000000000, mid, ans = 0;
vector<long long> v;

bool validate(int n) {
    int tmp = 0;    
    for(auto a : v){
        if (tmp >= M) return true;
        if(a - n > 0) tmp = tmp + (a-n);
    }
    return tmp >= M;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    while (l <= r) {
        mid = (l+r)/2;
        if(validate(mid)){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;
}