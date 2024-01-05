#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    if(b > a) return gcd(b, a);
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    ll answer = 1, a, b, c;
    queue<ll> q;
    for(auto a : arr) q.push((ll)a);
    while(q.size() != 1){
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        c = gcd(a, b);
        q.push(a * b / c);
    }
    return q.front();
}