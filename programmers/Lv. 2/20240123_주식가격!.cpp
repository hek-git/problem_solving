#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;
    answer[prices.size() - 1] = -1;
    s.push(prices.size() - 1);
    for (int i = prices.size() - 2; i >= 0; i--) {
        while (!s.empty() && prices[i] <= prices[s.top()]) s.pop();
        if (s.empty())
            answer[i] = -1;
        else
            answer[i] = s.top();
        s.push(i);
    }
    for (int i = answer.size() - 1; i >= 0; i--) {
        if (answer[i] == -1)
            answer[i] = answer.size() - i - 1;
        else
            answer[i] = answer[i] - i;
    }
    return answer;
}