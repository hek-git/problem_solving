#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

typedef long long ll;

ll A, B, ans;

int bfs(pair<ll, ll>s, ll d){

    queue<pair<ll, ll>> q;
    q.push(s);

    while(!q.empty()){
        pair<ll, ll> source = q.front();
        q.pop();
        if(source.first == d) return source.second + 1;
        if(source.first*2 <= d) q.push(make_pair(source.first * 2, source.second + 1));
        if(source.first*10 + 1 <= d) q.push(make_pair(source.first * 10 + 1, source.second + 1));
    }
    return -1;
}

int main() {
    cin >> A >> B;
    ans = bfs(make_pair(A, 0), B);
    cout << ans;
}
