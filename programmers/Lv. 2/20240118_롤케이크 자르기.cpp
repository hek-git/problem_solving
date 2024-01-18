#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp_left[1000000], dp_right[1000000], number[10001];

int solution(vector<int> topping) {
    int answer = 0;
    dp_left[0] = dp_right[topping.size() - 1] = 1;
    number[topping[0]]++;
    for (int i = 1; i < topping.size(); i++) {
        dp_left[i] = dp_left[i - 1];
        if (!number[topping[i]]) {
            number[topping[i]]++;
            dp_left[i]++;
        }
    }
    for (int i = 0; i <= 10000; i++) number[i] = 0;
    number[topping[topping.size() - 1]]++;
    for (int i = topping.size() - 2; i >= 0; i--) {
        dp_right[i] = dp_right[i + 1];
        if (!number[topping[i]]) {
            number[topping[i]]++;
            dp_right[i]++;
        }
    }
    for(int i = 0; i < topping.size() - 1; i++){
        if(dp_left[i] == dp_right[i + 1]) answer++;
    }

    return answer;
}