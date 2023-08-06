#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, point, P, num, ans = -1;
vector<int> v;
vector<int> rnk;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> N >> point >> P;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), cmp);
    num = 1;
    rnk.push_back(num);
    for (int i = 1; i < N; i++) {
        num++;
        if (v[i] == v[i - 1])
            rnk.push_back(rnk[i - 1]);
        else
            rnk.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        if (N == P) {
            if (point >= v[i] && point!= v[N-1]) {
                ans = rnk[i];
                break;
            }
        } else {
            if (point >= v[i]) {
                ans = rnk[i];
                break;
            }
        }
    } 
    //  for (int i = 0; i < N; i++) {
    //    cout << rnk[i] << " ";
    // }
    if (N == 0) ans = 1;
    else if(N < P && ans == -1){
        if(point == v[N-1]) ans = rnk[N-1];
        else ans = num + 1;
    } 
    
    cout << ans;
}