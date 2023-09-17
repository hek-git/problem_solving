#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int NANO = 10000000;
int x, n, l, hi, lo;
vector<int> length;

void solve(vector<int>& v, int n){
    lo = 0;
    hi = n - 1;
    while(lo < hi){
        int width = (length[lo] + length[hi])/NANO;
        if(width < x) lo++;
        else if(width > x) hi--;
        else{
            cout << "yes " << length[lo] << " " << length[hi] << '\n';
            return;
        }
    }
    cout << "danger\n";
}

int main() {
    
    ios::sync_with_stdio(false);
	cin.tie();
    cout.tie();

    while(true){
        cin >> x >> n;
        if(cin.eof())
            break;
        length.clear();
        for(int i = 0; i<n; i++){
            cin >> l;
            length.push_back(l);
        }
        sort(length.begin(), length.end());
        solve(length, n);
    }
}