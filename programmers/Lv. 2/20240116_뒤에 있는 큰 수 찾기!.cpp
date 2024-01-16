#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// 스택을 이용한 풀이
// vector<int> solution(vector<int> numbers) {
//     vector<int> answer;
//     stack<int> s;
//     reverse(numbers.begin(), numbers.end());
//     answer.push_back(-1);
//     s.push(numbers[0]);
//     for (int i = 1; i < numbers.size(); i++) {
//         while (!s.empty() && numbers[i] >= s.top()) s.pop();
//         if (s.empty())
//             answer.push_back(-1);
//         else
//             answer.push_back(s.top());
//         s.push(numbers[i]);
//     }
//     reverse(answer.begin(), answer.end());
//     return answer;
// }

// dp를 이용한 풀이
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    reverse(numbers.begin(), numbers.end());
    for(int i = 1; i < numbers.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(numbers[i] < numbers[j]) {
                answer[i] = numbers[j];
                break;
            }
            else if(numbers[i] >= numbers[j]){
                if(numbers[i] < answer[j]){
                    answer[i] = answer[j];
                    break;
                } else if(answer[j] == -1) break;
                
            }
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}