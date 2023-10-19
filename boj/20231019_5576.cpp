#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a, b;


int main() {
    for(int i = 0; i < 10; i++){
        cin >> N;
        a.push_back(N);
    }
    for(int i = 0; i < 10; i++){
        cin >> N;
        b.push_back(N);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a[9] + a[8] + a[7] << endl;
    cout << b[9] + b[8] + b[7] << endl;
}