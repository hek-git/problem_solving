#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, idx = 0;
    sort(routes.begin(), routes.end());
    while(idx != routes.size()){
        int end = routes[idx][1];
        while(routes[idx][0] <= end) {
            if(idx == routes.size()) break;
            end = min(end, routes[idx][1]);
            idx++;   
        }
        answer++;
    }
    return answer;
}