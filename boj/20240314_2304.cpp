#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L, H, answer, i, highest;
vector<pair<int, int>> P;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L >> H;
        P.push_back(make_pair(L, H));
    }
    sort(P.begin(), P.end(), cmp);
    for(int i = 0; i < P.size(); i++) highest = P[i].second > P[highest].second ? i : highest;
    

    while(true){
        pair<int, int> start = P[i];
        if(P[i].second == P[highest].second) break;
        for(int j = i; j < P.size(); j++){
            if(start.second < P[j].second){
                answer = answer + (P[j].first - start.first) * start.second; 
                i = j;
                break;
            }
        }
    }

    while(true){
        if(i == P.size() - 1) break;
        int low = 0, low_i = 0;
        for(int j = i + 1; j < P.size(); j++){
            if(low < P[j].second){
                low = P[j].second;
                low_i = j;
            }
        }
        answer = answer + (P[low_i].first - P[highest].first) * P[low_i].second + (P[highest].second - P[low_i].second);
        highest = low_i;
        i = low_i;        
    }
    answer += P[i].second;

    cout << answer;
}