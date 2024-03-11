#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>& sticker, int s, int i, int num) {
    int next1 = (i + 2) % sticker.size();
    int next2 = (i + 3) % sticker.size();

    if (next1 == s || next2 == s + 1 || next1 == ((s + sticker.size() - 1) % sticker.size())) return num;

    if (next2 == ((s + sticker.size() - 1) % sticker.size()))
        return dfs(sticker, s, next1, num + sticker[i + 2]);

    return max(dfs(sticker, s, next1, num + sticker[i + 2]),
               dfs(sticker, s, next2, num + sticker[i + 3]));
}

int solution(vector<int> sticker) {
    if (sticker.size() < 3) return (max({sticker[0], sticker[1], sticker[2]}));
    return max({dfs(sticker, 0, 0, sticker[0]), dfs(sticker, 1, 1,
    sticker[1]), dfs(sticker, 2, 2, sticker[2])});
}