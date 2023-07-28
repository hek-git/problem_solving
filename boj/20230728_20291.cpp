#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;
string file, sub;
int N, idx;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> file;
        idx = file.find('.') + 1;
        sub = file.substr(idx, file.size()-idx);
        if(m.find(sub) == m.end()) m.insert({sub, 1});
        else m[sub]++;
    }
    
    for(auto a : m){
        cout << a.first << " " << a.second << endl;
    }

}