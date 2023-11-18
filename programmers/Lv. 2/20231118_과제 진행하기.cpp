#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(vector<int>&a, vector<int>& b){
    if(a[1] == b[1]) return a[2] <= b[2];
    return a[1] < b[1];
}

int timeDifference(vector<int>&a, vector<int>& b){
    int t, m;
    if(a[2] < b[2]){
        m = a[2] - b[2] + 60;
        a[1]--;
    }else m = a[2] - b[2];
    t = a[1] - b[1];
    return t * 60 + m;
}

vector<int> setOrder(vector<vector<int>>& plans){
    deque<vector<int>> dq;
    deque<pair<int, int>> stopped;
    vector<int> order;
    for(int i = 0; i < plans.size(); i++){
        dq.push_back(plans[i]);
    }
    while(true){
        vector<int> assignment = dq.front();
        dq.pop_front();
        if(dq.empty()){
            order.push_back(assignment[0]);
            break;
        }
        assignment[1] = assignment[1] + (assignment[2] + assignment[3]) / 60;
        assignment[2] = (assignment[2] + assignment[3]) % 60;
        int time = timeDifference(assignment, dq.front());
        if(time > 0){
            stopped.push_back(make_pair(assignment[0], time));
        }
        else{
            order.push_back(assignment[0]);
            if(time == 0) continue;
            time = -time;
            while(time > 0 && !stopped.empty()){
                if(stopped.back().second - time > 0){
                    stopped.back().second -= time;
                    time = 0;
                }
                else{
                    time -= stopped.back().second;
                    order.push_back(stopped.back().first);
                    stopped.pop_back();
                }
            }
        }
    }
    while(!stopped.empty()){
        order.push_back(stopped.back().first);
        stopped.pop_back();
    }
    // for(int i = 0; i < order.size(); i++){
    //     cout << order[i] << " ";
    // }
    // cout << endl;
    return order;
}

vector<string> solution(vector<vector<string>> plans) {
    map<int, string> course;
    vector<int> order;
    vector<vector<int>> parsedPlans;
    vector<string> answer;
    for(int i = 0; i < plans.size(); i++){
        vector<int> tmp;
        course.insert({i, plans[i][0]});
        tmp.push_back(i);
        tmp.push_back(stoi(plans[i][1].substr(0, 2)));
        tmp.push_back(stoi(plans[i][1].substr(3, 2)));
        tmp.push_back(stoi(plans[i][2]));
        parsedPlans.push_back(tmp);
    }
    sort(parsedPlans.begin(), parsedPlans.end(), cmp);
    order = setOrder(parsedPlans);
    for(int i = 0; i < order.size(); i++){
        answer.push_back(course[order[i]]);
    }
    return answer;
}