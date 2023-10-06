#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<3; i++){
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    cout << v[1];
    
}