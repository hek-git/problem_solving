#include <iostream>
#include <set>

using namespace std;

int N, n, num[100001];
set<int> s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> n;
        if(s.find(n) == s.end()) s.insert(n);
    }

    for(auto a : s) cout << a << " ";

}