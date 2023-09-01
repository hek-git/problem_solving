#include <iostream>
#include <queue>

using namespace std;

int N, num;
priority_queue<pair<int, int>> q;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> num;
        if(num > 0) q.push(make_pair(-num, -1));
        else if(num < 0) q.push(make_pair(num, 1));
        else{
            if(q.empty()){
                cout << "0\n";
                continue;
            }
            pair<int, int> p = q.top();
            cout << p.first * p.second << '\n';
            q.pop();
        }
    }
    
}