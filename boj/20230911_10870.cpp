#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int fibo(int N){
    if(N<=1) return N;
    return fibo(N-1) + fibo(N-2);
}

int main() {
    cin >> N;
    cout << fibo(N);

}