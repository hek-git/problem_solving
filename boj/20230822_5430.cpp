#include <deque>
#include <iostream>
#include <string>

using namespace std;

int T, n, flag;
string p, array;
deque<int> number;

deque<int> parseToInt(string& array) {
    deque<int> n;
    string tmp;

    for (int i = 1; i < array.size() - 1; i++) {
        if (array[i] == ',') {
            n.push_back(stoi(tmp));
            tmp.clear();
        } else
            tmp += array[i];
    }
    if (tmp.size()) n.push_back(stoi(tmp));

    return n;
}

bool solve(string& p, deque<int>& number) {
    for (auto c : p) {
        if (c == 'R')
            flag = !flag;
        else {
            if (number.empty())
                return false;
            else if (flag)
                number.pop_back();
            else
                number.pop_front();
        }
    }
    return true;
}

void printArray(deque<int>& number) {
    cout << "[";
    if (flag) {
        while (number.size() > 1) {
            cout << number.back() << ",";
            number.pop_back();
        }
    } else {
        while (number.size() > 1) {
            cout << number.front() << ",";
            number.pop_front();
        }
    }
    if(!number.empty()) cout << number.front() << "]\n";
    else cout << "]\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> p >> n >> array;

        flag = 0;
        number = parseToInt(array);

        if (!solve(p, number))
            cout << "error\n";
        else
            printArray(number);
    }
}