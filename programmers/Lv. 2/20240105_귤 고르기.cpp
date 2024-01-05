#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, int> m; // 무게 : 개수 매핑 정보를 가지는 map
vector<pair<int, int>> tangerine_num; // 개수, 무게 쌍을 가지는 vector

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    k = tangerine.size() - k; // k는 빼야하는 귤의 개수로 정함 (전체 귤 개수 - 골라야하는 귤 개수)
    for(auto t : tangerine){  // 귤의 무게 : 개수 매핑
        if(m.find(t) != m.end()) m[t]++;
        else m[t] = 1;
    }
    // 귤 무게 : 수량으로 매핑된 정보를 이용해 pair vector를 만들고 개수를 기준으로 정렬
    for(auto a : m) tangerine_num.push_back(make_pair(a.second, a.first));
    sort(tangerine_num.begin(), tangerine_num.end());

    // 개수가 적은 무게의 귤부터 빼가며 뺄 수 있는 귤이 없을 때 까지 계속 뺀다 (greedy)
    for(int i = 0; i < tangerine_num.size(); i++){
        if(k - tangerine_num[i].first >= 0){
            k = k - tangerine_num[i].first;
            tangerine_num[i].first = 0; // 해당 무게의 귤은 0개            
        } else break;
    }

    // 개수가 0이 아닌 귤에 대해서 종류 추가
    for(auto t : tangerine_num){
        if(t.first != 0) answer++;
    }

    return answer;
}