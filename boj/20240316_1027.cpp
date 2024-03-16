#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int N, n, answer;
vector<int> building;

bool solve(int i, int j, pair<int, int>& p1, pair<int, int>& p2){
    double dx = (double)p1.first - (double)p2.first;
    double dy = (double)p1.second - (double)p2.second;
    double x1 = (double)p1.first;
    double y1 = (double)p1.second;
    int tmp = i;
    while(i < j){
        double y = ((double)i - x1) * dy / dx + y1;
        if((double)building[i] >= y) return false;
        i++;
    }
    return true;
}

int main() {
    cin >> N;
    building.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> n;
        building.push_back(n);
    }

    for(int i = 1; i <= N; i++){
        int tmp = -1;
        pair<int, int> p1 = make_pair(i, building[i]);
        for(int j = 1; j <= N; j++){
            if(abs(i - j) <= 1) {
                tmp++;
                continue;
            }
            pair<int, int> p2 = make_pair(j, building[j]);
            if(solve(min(i, j) + 1, max(i, j), p1, p2)) tmp++;
        }
        answer = max(answer, tmp);
    }
    cout << answer;
}