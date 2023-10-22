#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, ans;
vector<int> light, interval;

void solve(int n){
    for(int i = 0; i < interval.size(); i++){
        ans += (interval[i] / n - 1);
    }
}

int gcd(int a, int b){
    if(b == 0) return a;
    if(b > a) return gcd(b, a);
    return gcd(b, a%b);
}

int gcd(vector<int> n){
    int tmp = n[0];
    for(int i = 1; i < n.size() ; i++){
        tmp = gcd(tmp, n[i]);
    }
    return tmp;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        light.push_back(num);
    }
    for(int i = 1; i < N; i++){
        interval.push_back(light[i] - light[i-1]);
    }

    solve(gcd(interval));
    cout << ans;
}