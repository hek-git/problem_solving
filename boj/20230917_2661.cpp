#include <iostream>
#include <string>

using namespace std;

int N, flag, list[3] = {1, 2, 3};
string number;

bool validate(string number) {
    for(int i = 0; i < number.size(); i++){
        for(int j = 1; j < (number.size()- i)/2 + 1; j++){
            string a = number.substr(i, j);
            string b = number.substr(i + j, j);
            if(!a.compare(b)){
                return false;
            }
        }
    }
    return true;
}

void solve(int len, int previous) {
    if (len == N) {
        cout << number;   
        exit(0);
    }

    for (int i = 1; i <= 3; i++) {
        if(!(previous == i)){
            number.push_back(i+'0');
            if(validate(number)){
                solve(len + 1, i);
            }
            number.pop_back();
        }
    }
}

int main() {
    cin >> N;
    solve(0, 0);
}