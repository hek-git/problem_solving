#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string number;
vector<int> ans;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    cin >> number;
    for(int i = 0; i <number.size(); i++){
        ans.push_back(number[i]-'0');
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0 ; i<ans.size(); i++){
        cout << ans[i];
    }
}