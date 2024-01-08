#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int& a, int& b){ return a > b;}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), cmp);
    for(int i = citations.size() ; i > 0; i--){
        if(i <= citations[i-1]) return i;
    }
    return answer;
}