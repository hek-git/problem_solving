#include <string>
#include <vector>

using namespace std;

int answer, check[14];
vector<pair<int, int>> queen;

bool validate(vector<pair<int, int>>& queen, pair<int, int> p){
    for(int i = 0; i < queen.size(); i++){
        int queen_y = queen[i].first, queen_x = queen[i].second;
        if((p.first - queen_y == p.second - queen_x) || (p.first - queen_y == queen_x - p.second)) return false;
    }
    return true;
}

void back_track(int n, int y) {
    if (queen.size() == n) {
        answer++;
        return;
    }

    for (int x = 0; x < n; x++) {
        pair<int, int> tmp = make_pair(y, x);
        if (!check[x] && validate(queen, tmp)) {
            check[x] = 1;
            queen.push_back(tmp);
            back_track(n, y + 1);
            check[x] = 0;
            queen.pop_back();
        }
    }
}

int solution(int n) {
    back_track(n, 0);
    return answer;
}