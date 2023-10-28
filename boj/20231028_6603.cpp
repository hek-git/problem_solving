#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n;
vector<int> number;
vector<int> ans;

void solve(int idx){
    if(ans.size() == 6){
        for(int i = 0 ; i < ans.size(); i++){
            cout << ans[i] << " "; 
        }
        cout << '\n';
    }

    for(int i = idx; i < number.size(); i++){
        ans.push_back(number[i]);
        solve(i+1);
        ans.pop_back();
    }
}

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    while(true){
        cin >> N;
        number.clear();
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            cin >> n;
            number.push_back(n);
        }
        solve(0);
        cout << '\n';
    }
}