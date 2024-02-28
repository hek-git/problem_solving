#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 3000000000000000000

using namespace std;

typedef long long ll;

bool check(int n, vector<int>& times, ll time) {
    ll p = 0;
    // cout << time << endl;
    for (int i = 0; i < times.size(); i++){
        p += time / times[i];
        if (p >= n) return true;
    }
    return false;
}

ll binary_search(int n, vector<int>& times) {
    ll lo = 0, hi = MAX, mid, answer = MAX;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(n, times, mid)){
            hi = mid - 1;
            answer = min(answer, mid);
        } else{
            lo = mid + 1;
        } 
    }
    return answer;
}

ll solution(int n, vector<int> times) { return binary_search(n, times); }