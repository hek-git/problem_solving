#include <iostream>
#include <string>

using namespace std;

int T, a, b, c;

int main() {
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> a >> b >> c;
        if(b - c > a) cout << "advertise\n";
        else if(b-c == a) cout << "does not matter\n";
        else if(b - c < a) cout << "do not advertise\n";
    }
}
