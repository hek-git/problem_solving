#include <iostream>
using namespace std;

int solution(int n){
    int ans = 0;
    while(n){
        if(n%2 == 0) n/=2;
        else{
            ans++;
            n-=1;
        }
    }
    return ans;
}