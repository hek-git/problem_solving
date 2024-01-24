#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll n[1001];
pair<ll, ll> ratio[6] = {{2, 3}, {3, 2}, {2, 4}, {4, 2}, {3, 4}, {4, 3}};

ll solution(vector<int>& list, int i) {
    ll correct = 0;
    for (int j = i + 1; j < list.size(); j++) {
        for (int k = 0; k < 6; k++) {
            if (list[i] * ratio[k].first == list[j] * ratio[k].second) {
                correct = correct + n[list[i]] * n[list[j]];
                break;
            }
        }
    }
    return correct;
}

ll solution(vector<int> weights) {
    ll answer = 0;
    vector<int> list;
    for (int i = 0; i < weights.size(); i++) {
        if (!n[weights[i]]) list.push_back(weights[i]);
        n[weights[i]]++;
    }

    for (int i = 100; i < 1001; i++) answer = answer + (n[i] * (n[i] - 1)) / 2;
    for (int i = 0; i < list.size() - 1; i++) answer += solution(list, i);
    return answer;
}