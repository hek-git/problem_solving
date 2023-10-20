#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int first, second, ans, lcs[1001][1001];
string A, B;

int main() {
    cin >> A >> B;
    for(int i = 1; i <= B.size(); i++){
        for(int j = 1; j <= A.size(); j++){
            if(B[i - 1] == A[j - 1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            ans = max(ans, lcs[i][j]);
        }
    }
    for(int i = 1; i <= B.size(); i++){
        for(int j = 1; j <= A.size(); j++){
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans;
}