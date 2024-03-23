#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll T, K, k, answer;

int main() {
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> K;
        
        priority_queue<ll> pq;
        answer = 0;
                
        for(int j = 0; j < K; j++){
            cin >> k;
            pq.push(-k);
        }

        while(pq.size() > 1){
            ll k1, k2;
            k1 = pq.top();
            pq.pop();
            k2 = pq.top();
            pq.pop();
            pq.push(k1 + k2);
            answer += k1 + k2;
        }
        cout << -answer << endl;
    }
}