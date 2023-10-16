#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N, n, gap;

int main() {
    cin >> T;
    for(int i = 0; i < T; i++){
        gap = 0;
        cin >> N;
        vector<int> v;
        for(int j = 0; j<N; j++){
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        for(int j = 1; j<N; j++){
            gap = max(gap, v[j] - v[j-1]);
        }
        cout << "Class " << i+1 << endl;
        cout << "Max " << v[N-1] << ", Min " << v[0] << ", Largest gap " << gap << endl;
        
    }
}