#include <iostream>
#include <string>
#include <vector>

using namespace std;

int global_target, answer;
vector<int> global_numbers, operands;

// 만들어진 경우의 수로 계산
int calculate() {
    int n = 0;
    for (int i = 0; i < operands.size(); i++) {
        if (operands[i])
            n -= global_numbers[i];
        else
            n += global_numbers[i];
    }
    return n;
}

// 모든 연산자의 경우의 수를 구하고 계산하는 풀이
void solution() {
    if (operands.size() == global_numbers.size()) {
        int n = calculate();
        if (n == global_target) answer++;
    } else {
        for (int i = 0; i < 2; i++) {
            operands.push_back(i);
            solution();
            operands.pop_back();
        }
    }
}

int solution(vector<int> numbers, int target) {
    global_numbers = numbers, global_target = target;
    solution();
    return answer;
}

// dfs 풀이
// int answer;

// void dfs(vector<int>& numbers, int& target, int num, int n){
//     if(n == numbers.size()){
//         if(num == target) answer++;
//         return;
//     }
//     dfs(numbers, target, num + numbers[n], n + 1);
//     dfs(numbers, target, num - numbers[n], n + 1);
// }

// int solution(vector<int> numbers, int target) {
    
//     dfs(numbers, target, numbers[0], 1);
//     dfs(numbers, target, -numbers[0], 1);
    
//     return answer;
// }