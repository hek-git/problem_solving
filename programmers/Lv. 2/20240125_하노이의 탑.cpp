#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> n1, n2;
    vector<int> mid(2);
    mid[0] = 1, mid[1] = 3;
    n1.push_back(mid);
    for(int i = 1; i < n; i++){
        vector<int> tmp(2);
        for(int j = 0; j < n1.size(); j++){
            tmp[0] = (n1[j][0] == 1) ? 1 : (n1[j][0] == 2) ? 3 : 2;
            tmp[1] = (n1[j][1] == 1) ? 1 : (n1[j][1] == 2) ? 3 : 2;
            n2.push_back(tmp);
        }
        n2.push_back(mid);
        for(int j = 0; j < n1.size(); j++){
            tmp[0] = (n1[j][0] == 3) ? 3 : (n1[j][0] == 2) ? 1 : 2;
            tmp[1] = (n1[j][1] == 3) ? 3 : (n1[j][1] == 2) ? 1 : 2;
            n2.push_back(tmp);
        }
        n1 = n2;
        n2.clear();
    }
    return n1;
}