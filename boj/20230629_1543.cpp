#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    int i = 0, s_size, cnt, ans = 0;
    string T, S;
    getline(cin, T);
    getline(cin, S);
    for (int i = 0; i < T.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            if(T[i+j]!=S[j]) break;
            if(j==S.size()-1){
                ans++;
                i+=j;
            }
        }
    }
    cout << ans;
}