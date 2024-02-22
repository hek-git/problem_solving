#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int r, end;
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }
    r = s % n;
    for(int i = 0; i < n; i++) answer.push_back(s / n);
    while(r--) answer[--n]++;
    return answer;
}