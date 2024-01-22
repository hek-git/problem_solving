#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

string to_binary(ll number){
    string binary;
    while(number){
        binary.push_back(number % 2 + '0');
        number /= 2;
    }
    binary.push_back('0');
    reverse(binary.begin(), binary.end());
    return binary;
}

ll to_number(string binary){
    ll number = 0;
    reverse(binary.begin(), binary.end());
    for(int i = 0; i < binary.size(); i++){
        if(binary[i] == '1') number = number + (ll)pow(2, i);
    }
    return number;
}

ll solution(ll number){
    string binary = to_binary(number);
    int idx = 0;
    reverse(binary.begin(), binary.end());
    // 가장 가까운 0을 찾아서 1로 변경 -> 비트가 한 자리 다르고 number보다 큰 수 중 가장 작은 수
    while(binary[idx] == '1') idx++;
    binary[idx] = '1';
    
    // 찾은 0의 위치에서 가장 가까운 1을 찾아 0으로 변경 -> 비트가 두 자리 다르고 number보다 큰 수 중 가장 작은 수 
    for(int i = idx - 1; i >= 0; i--){
        if(binary[i] == '1'){
            binary[i] = '0';
            break;
        }
    }
    reverse(binary.begin(), binary.end());
    return to_number(binary);
}

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for(auto n : numbers) answer.push_back(solution(n));
    return answer;
}