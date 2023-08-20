#include <iostream>
#include <vector>

using namespace std;

int N, ans, cnt = 1, d = 2, num;
vector<int> v;

int main() {

    cin >> N;

    v.push_back(0);
    v.push_back(1);
    while(num < 1000000000){
        num = 6 * cnt + 1;
        v.push_back(num);
        cnt += d;
        d++;
    }

    for(int i=0; i<v.size(); i++){
        if(N <= v[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}