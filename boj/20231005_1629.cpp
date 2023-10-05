#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, C, ans, tmp = 1, cnt;

int solve(int n){
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;

    while(true){
        if(tmp*2 > B){
            break;
        }
        tmp *= 2;
        cnt++;
    }
    cout << cnt;
    solve(tmp);
}