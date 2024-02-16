#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int check(vector<int>& cards) {
    for(int i = 0; i < cards.size(); i++){
        if(cards[i] != -1) return i;
    }
    return -1;
}

bool cmp(int a, int b){return a >= b;}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> group;
    while (true) {
        int idx = check(cards), n = 0, tmp;
        if(idx == -1) break;
        while(cards[idx] != -1){
            n++;
            tmp = cards[idx] - 1;
            cards[idx] = -1;
            idx = tmp;
        }
        group.push_back(n);
    }
    sort(group.begin(), group.end(), cmp);
    group.push_back(0);
    answer = group[0] * group[1];
    return answer;
}