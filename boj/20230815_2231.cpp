#include <iostream>

using namespace std;

int N, ans;

int solve(int n){

    int cpy = n;
    
    while(n>0){
        cpy += n%10;
        n/=10;
    }
    return cpy;
}

int main() {

    cin >> N;

    while(true){
        if(ans > N) break;
        if(solve(ans) == N){
            cout << ans;
            return 0;
        }
        ans++;
    }
    cout << 0;

}