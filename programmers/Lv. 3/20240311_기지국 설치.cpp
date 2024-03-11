#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0, start = 1, term;
    for(int i = 0; i < stations.size(); i++){
        term = stations[i] - w - start;
        start = stations[i] + w + 1;
        if(term <= 0) continue;
            answer = answer + term / (1 + w * 2);
            if(term % (1 + w * 2)) answer++;
    }
    if(start <= n){
        term = n + 1 - start;
        answer = answer + term / (1 + w * 2);
        if(term % (1 + w * 2)) answer++;
    }

    return answer;
}