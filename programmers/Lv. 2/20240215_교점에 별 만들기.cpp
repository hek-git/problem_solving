#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 2000000000000000

using namespace std;

typedef long long ll;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<ll, ll>> point;
    ll max_x = -INF, max_y = -INF, min_x = INF, min_y = INF;
    for(int i = 0; i < line.size(); i++){
        for(int j = i + 1; j < line.size(); j++){
            ll l = (ll)1 * line[i][0] * line[j][1] - (ll)1 * line[i][1] * line[j][0];
            ll x = (ll)1 * line[i][1] * line[j][2] - (ll)1 * line[i][2] * line[j][1];
            ll y = (ll)1 * line[i][2] * line[j][0] - (ll)1 * line[i][0] * line[j][2];
            if(l == 0 || x % l != 0 || y % l !=0) continue;
            x /= l, y /= l;
            point.push_back(make_pair(y, x));
            max_x = max(max_x, x), max_y = max(max_y, y);
            min_x = min(min_x, x), min_y = min(min_y, y);
        }
    }
    
    for(ll i = min_y; i <= max_y; i++){
        string tmp;
        for(ll j = min_x; j <= max_x; j++){
            tmp.push_back('.');
        }
        answer.push_back(tmp);
    }

    for(int i = 0; i < point.size(); i++){
        answer[max_y - point[i].first][point[i].second - min_x] = '*';
    }
    
    return answer;
}