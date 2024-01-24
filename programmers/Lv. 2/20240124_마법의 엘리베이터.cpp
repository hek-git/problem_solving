#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(int storey, int num) {
    if(storey == 0) return num;
    int storey1, storey2;
    int plus = 10 - storey % 10, minus = storey % 10;
    storey1 = (storey + plus) / 10, storey2 = (storey - minus) / 10;
    if(storey2 == 0 && num + minus <= num + plus) return num + minus;
    return min(dfs(storey1, num + plus), dfs(storey2, num + minus));
}

int solution(int storey) { return dfs(storey, 0); }