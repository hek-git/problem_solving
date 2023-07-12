#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, ans=0, num;
    vector<int> coin;
    cin >> N >> K;
    for(int i=0; i< N; i++){
        cin >> num;
        coin.push_back(num);
    }
    reverse(coin.begin(), coin.end());
    
    for(auto c : coin){
        if(K >= c){
            ans+=K/c;
            K%=c;
        }
    }
    cout << ans;
}
