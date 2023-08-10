#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, ans = 0;
vector<int> v;

int main() {

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }

    for(int i=0; i<n;i++){
        unordered_set<int> s;
        int cnt=0;
        for(int j=i; j<n; j++){
            if(s.find(v[j]) == s.end()){
                s.insert(v[j]);
                cnt++;
            }
            else break;
        }
        ans = max(cnt, ans);
    }

    cout << ans;
    return 0;
}