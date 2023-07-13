#include <iostream>

using namespace std;

int main() {
    int num = 0, solve[10036] = { 0, }, m;
    for (int i = 0; i <= 9999; i++) {
        m = num = i;
        while (m) {
            num+=m%10;
            m/=10;
        }
        solve[num]=1;
        num = 0;
    }
    for(int i=0; i<=10000; i++){
        if(!solve[i]) cout << i << endl;
    }
}