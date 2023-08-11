#include <iostream>
#include <queue>

using namespace std;

int N, K, cnt;
queue<int> q;
vector<int> ans;

int main() {
    
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            q.push(q.front());
            cout << q.front() << "!" << endl;
            q.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for(int i=0; i<ans.size(); i++){
        if(i==ans.size()-1) cout << ans[i];
        else cout << ans[i] << ", ";
    }
    cout << ">";

}