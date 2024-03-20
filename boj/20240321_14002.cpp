#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n, longest;
vector<int> list, answer, dp(1001, 1);

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        list.push_back(n);
    }

    for(int i = 1; i < N; i++){
        for(int j = i - 1; j >= 0; j--){
            if(list[i] > list[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    longest = *max_element(dp.begin(), dp.end());
    cout << longest << endl;

    for(int i = N - 1; i >= 0; i--){
        if(dp[i] == longest){
            answer.push_back(list[i]);
            longest--;
        } 
    }
    
    for(int i = answer.size() - 1; i >= 0; i--) cout << answer[i] << " ";
}