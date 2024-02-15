#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    ll max_n = min((ll)10000000, end/2);
    for(ll i = begin; i <= end; i++){
        int n = (i == 1) ? 0 : 1;
        int max_j = -1;
        for(ll j = 2; j <= (ll)sqrt(i); j++){
            if(i % j == 0){
                if((i / j) > max_n){
                    max_j = max((int)j, max_j);
                }
                else {
                    n = i / j;
                    break;
                }
            }
        }
        answer.push_back(max(n, max_j));
    }
    
    return answer;
}