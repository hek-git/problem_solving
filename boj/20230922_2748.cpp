#include <iostream>

using namespace std;

int N;
long long memo[91];

long long fibo(long long n){
    if(memo[n]) return memo[n];
    if(n <= 1) return n; 
    return memo[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    cin >> N;
    cout << fibo(N);
}