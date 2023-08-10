#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int ans = -1, num, n, rnk=1, cmp = 100001;
unordered_map<int, pair<int, int>> m;

int main() {
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        if(m.find(num) == m.end()){
            m[num] = make_pair(1 ,rnk);
            rnk++;
        }
        else m[num].first++;
    }

    for(auto& a : m){
        if(a.second.first == 1){
            if(cmp > a.second.second) {
                cmp = a.second.second;
                ans = a.first;
            }
        }
    }
    cout<< ans;

    return 0;
}