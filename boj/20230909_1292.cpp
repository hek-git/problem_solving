#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> v;

int main() {
    
    cin >> N >> M;
    for(int i = 1; i<=100; i++){
        for(int j = 0; j<i; j++){
            v.push_back(i);
        }
    }

    for(int i = 0; i<M; i++){
        ans += v[i];
    }
    for(int i = 0; i<N-1; i++){
        ans -= v[i];
    }
    cout << ans;

}