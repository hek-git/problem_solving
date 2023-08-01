#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, ans;
vector<int> rope;

int main()
{
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> num;
        rope.push_back(num);
    }
    sort(rope.begin(), rope.end());
    
    for(int i=0; i<N; i++){
        int tmp = rope[i] * (N-i);
        if(ans < tmp) ans = tmp;
    }
    cout << ans;
    
    return 0;
}
