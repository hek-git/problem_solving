#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, num;
priority_queue<int> pq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        if(!num){
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else pq.push(num);
    }
}