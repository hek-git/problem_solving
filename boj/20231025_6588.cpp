#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, primeNumber[1000001];

void prime(){
    for(int i = 2; i < 1000001; i++){
        if(primeNumber[i]) continue;
        for(int j = 2; j * i < 1000001; j++){
            primeNumber[i * j] = 1;
        }
    }
}

void solve(int N){
    for(int i = 3; i <= N/2; i+=2){
        if(i%2 == 0) continue;
        if(!primeNumber[i] && !primeNumber[N - i]){
            cout << N << " = " << i << " + " << N - i << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    primeNumber[0] = 1;
    primeNumber[1] = 1;
    prime();
    while(true){

        cin>>N;
        if(!N) break;
        solve(N);   
    }
}