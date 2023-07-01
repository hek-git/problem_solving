#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, num, ans=0;
    vector<int> L;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> num;
        L.push_back(num);
    }
    sort(L.begin(), L.end());

    for(auto l : L){
        if(N<=1) break;
        if(l > N-2){
            ans += N-1;
            N = 1;
        }
        else if(l <= N-2){
            ans+=l;
            N-=(l+1);
        }
    }
    cout << ans;
}