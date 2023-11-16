#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[1000001];

pair<int, int> binarySearch(int i, int n, int k) {
    pair<int, int> idx;
    idx.first = 1000001;
    idx.second = 2000002;
    int hi = i;
    int lo = 0;
    int m;
    while (lo <= hi) {
        m = (lo + hi) / 2;
        if (n - dp[m] == k) {
            idx.first = m;
            idx.second = i - 1;
            return idx;
        } else if (n - dp[m] > k) {
            lo = m + 1;            
        } else if (n - dp[m] < k) {
            hi = m - 1;
        }
    }
    return idx;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(1000001);
    answer.push_back(2000002);
    pair<int, int> idx;
    for (int i = 0; i < sequence.size(); i++) {
        dp[i + 1] = dp[i] + sequence[i];
    }
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == k) {
            answer[0] = answer[1] = i;
            return answer;
        } else if (dp[i + 1] >= k) {
            pair<int, int> tmp = binarySearch(i + 1, dp[i + 1], k);
            if (tmp.second - tmp.first < answer[1] - answer[0]) {
                answer[0] = tmp.first;
                answer[1] = tmp.second;
            } else if (tmp.second - tmp.first == answer[1] - answer[0]) {
                if (tmp.first < answer[0] && tmp.second < answer[1]) {
                    answer[0] = tmp.first;
                    answer[1] = tmp.second;
                }
            }
            cout << tmp.first << " " << tmp.second << endl;
        }
    }
    return answer;
}