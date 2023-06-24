#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int main(){
    int n, A, ans=0;
    vector<int> num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A);
        num.push_back(A);
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    cout << endl;
    cout << "e";
    if (n == 1) ans = A*A;
    else ans = num[0]*(*num.end());
    cout<<ans;
}