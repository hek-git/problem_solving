#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 2, right[1000001], left[1000001];
    left[0] = a[0];
    right[a.size() - 1] = a.back();
    for(int i = 1; i < a.size(); i++){
        left[i] = min(left[i - 1], a[i]);
        right[a.size() - 1 - i] = min(right[a.size() - i], a[a.size() - 1 - i]);
    }

    if(a.size() <= 2) return a.size();
    for(int i = 1; i < a.size() - 1; i++){
        if(a[i] > left[i - 1] && a[i] > right[i + 1]) continue;
        answer++;
    }
    return answer;
}