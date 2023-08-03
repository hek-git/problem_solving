#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, a, b;
string ans;
vector<string> channels;

void swap(string& a, string& b) {
    string tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string c;
        cin >> c;
        if (!c.compare("KBS1")) a = i;
        if (!c.compare("KBS2")) b = i;
        channels.push_back(c);
    }

    if (a > b) b++;

    // for(int i=0; i<N; i++){
    //         cout << channels[i] << endl;
    // }
    // cout << endl;

    for (int i = 0; i < a; i++) {
        ans += "1";
    }
    for (int i = 0; i < a; i++) {
        ans += "4";
    }
    for (int i = 0; i < b; i++) {
        ans += "1";
    }
    for (int i = 1; i < b; i++) {
        ans += "4";
    }

    cout << ans;
}