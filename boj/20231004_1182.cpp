#include <iostream>
#include <vector>

using namespace std;

int N, S, n, ans, num[21];
vector<int> v;

void solve(int idx, int m){
    if(m == S){
        ans++;
    }
    for(int i = idx + 1; i<N; i++){
        solve(i, m+num[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(int i = 0; i<N; i++){
        cin >> n;
        num[i]=n;
    }
    for(int i = 0; i<N; i++){
        solve(i, num[i]);
    }
    cout << ans;
}