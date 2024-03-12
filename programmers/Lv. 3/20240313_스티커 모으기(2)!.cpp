#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp1[100001], dp2[100001];
int solution(vector<int> sticker) {
    int tmp = sticker.back();
    if (sticker.size() == 1) return sticker[0];
    
    sticker.pop_back();
    dp1[0] = sticker[0];
    dp2[0] = 0;

    dp1[1] = max(sticker[0], sticker[1]);
    dp2[1] = sticker[1];

    for (int i = 2; i < sticker.size(); i++)
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    sticker.push_back(tmp);
    for (int i = 2; i < sticker.size(); i++)
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);

    return max(dp1[sticker.size() - 2], dp2[sticker.size() - 1]);
}