#include <iostream>
#include <stack>

using namespace std;

int K, num, ans;
stack<int> s;

int main() {
    
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> num;
        if(!num) s.pop();
        else s.push(num);
    }

    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout << ans;
}