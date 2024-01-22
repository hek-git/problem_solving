#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, current_weight = 0, current_truck = 0;
    queue<int> bridge, trucks;
    for(int i = 0; i < truck_weights.size(); i++) trucks.push(truck_weights[i]);
    for(int i = 0; i < bridge_length; i++) bridge.push(0);
    while(!bridge.empty()){
        // 무게를 견딜 수 있으면
        current_weight -= bridge.front();
        bridge.pop();
        if(!trucks.empty() && current_weight + trucks.front() <= weight){
            current_weight += trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
        } else if(!trucks.empty())bridge.push(0);

        // queue<int> q = bridge;
        // while(!q.empty()){
        //     cout << q.front() << " ";
        //     q.pop();
        // } cout << endl;

        answer++;
    } 

    return answer;
}

int main(){
    vector<int> a;
    a.push_back(7);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    solution(2, 10, a);
}