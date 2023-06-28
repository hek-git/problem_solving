#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, S, R, num, ans;
    vector<int> s(11, 0);
    vector<int> r(11, 0);

    cin >> N >> S >> R;

    for (int i = 0; i < S; i++) {
        cin >> num;
        s[num]=1;
    }

    for (int i = 0; i < R; i++) {
        cin >> num;
        r[num]=1;
    }
    ans = S;
    for (int i = 0; i < R; i++) {
        if(s[r[i]]){
			ans--;
			s[r[i]]=0;
		} else if(s[r[i]-1]){
			ans--;
			s[r[i]-1]=0;
		} else if(s[r[i]+1]){
			ans--;
			s[r[i]+1]=0;
		}
    }
    cout << ans;
}