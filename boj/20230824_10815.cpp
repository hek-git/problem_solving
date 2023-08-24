#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int N, M, num;
unordered_set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        if(s.find(num) == s.end()) cout << 0 << " ";
        else cout << 1 << " ";
    }
}