#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

string formula, tmp;
queue<int> num;
queue<char> op;
int ans;

int main() {
    cin >> formula;

    for (int i = 0; i < formula.size(); i++) {
        if (formula[i] == '-' || formula[i] == '+') {
            op.push(formula[i]);
            num.push(stoi(tmp));
            tmp.clear();
        } else
            tmp += formula[i];
    }
    num.push(stoi(tmp));
    
    ans = num.front();
    num.pop();

    while(!op.empty()){

        int operand = num.front();
        char operate = op.front();
        num.pop();
        op.pop();

        if(operate == '-'){
            while(!op.empty() && op.front() != '-'){
                operand += num.front();
                num.pop();
                op.pop();
            }
            operand *= -1;
        }

        ans += operand;
    }

    cout << ans;
}