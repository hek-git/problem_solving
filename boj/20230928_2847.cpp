#include <iostream>
#include <vector>

using namespace std;

int N, num, ans;
vector<int> point;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> num;
        point.push_back(num);
    }

    for(int i = N-1; i > 0; i--){
        int d = 0;
        if(point[i-1] >= point[i]){
            d = point[i-1] - point[i] + 1;
            point[i-1] -= d;
        }
        ans += d;
    }
    cout << ans;
}