#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N, n;

bool cmp(pair<string, int>&a, pair<string, int>& b){
    return a.second < b.second;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        vector<pair<string, int>> v;
        for(int j = 0; j<N; j++){
            string s;
            cin >> s >> n;
            v.push_back(make_pair(s, n));
        }
        sort(v.begin(), v.end(), cmp);
        cout << v[N-1].first << endl;
    }
}