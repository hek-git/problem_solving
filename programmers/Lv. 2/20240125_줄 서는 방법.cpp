#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> answer, num;

ll factorial(ll n) {
    if (n < 2) return 1;
    ll a = 1;
    for (ll i = 1; i <= n; i++) a *= i;
    return a;
}

// vector에서 원소 n을 지우는 erase 함수 직접 구현
void erase(int n){
    vector<int> tmp;
    while(num.back() != n){
        tmp.push_back(num.back());
        num.pop_back();
    }
    num.pop_back();
    while(!tmp.empty()){
        num.push_back(tmp.back());
        tmp.pop_back();
    }
}

vector<int> dictionary_num(int n, ll k) {
    if (n == 0) return answer;
    ll f = factorial((ll)(n - 1));
    int q = k / f;
    answer.push_back(num[q]);
    // erase(num[q]);
    num.erase(num.begin() + q);
    return dictionary_num(n - 1, k % f);
}

vector<int> solution(int n, ll k) {
    for(int i = 1; i <= n; i++) num.push_back(i);
    return dictionary_num(n, k - 1);
}