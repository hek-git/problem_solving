#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define MULTIPLE 65536

using namespace std;

vector<string> set1, set2;
map<string, int> map1, map2;

string lower_case(string& s) {
    int diff = 'A' - 'a';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= diff;
    }
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    double u_set, i_set;
    str1 = lower_case(str1);
    str2 = lower_case(str2);

    for (int i = 0; i < str1.size() - 1; i++) {
        if (!(str1[i] >= 'a' && str1[i] <= 'z') ||
            !(str1[i + 1] >= 'a' && str1[i + 1] <= 'z'))
            continue;
        string tmp = str1.substr(i, 2);
        set1.push_back(tmp);
        if (map1.find(tmp) != map1.end())
            map1[tmp]++;
        else
            map1[tmp] = 1;
    }

    for (int i = 0; i < str2.size(); i++) {
        if (!(str2[i] >= 'a' && str2[i] <= 'z') ||
            !(str2[i + 1] >= 'a' && str2[i + 1] <= 'z'))
            continue;
        string tmp = str2.substr(i, 2);
        set2.push_back(tmp);
        if (map2.find(tmp) != map2.end())
            map2[tmp]++;
        else
            map2[tmp] = 1;
    }

    // 둘다 공집합인 경우 나눗셈X -> 곱셈 상수 반환
    if (set1.empty() && set2.empty()) return MULTIPLE;

    // 합집합 개수(기본적으로 1번 집합의 원소 개수)
    i_set = set1.size();

    // 교집합 원소 개수를 구하는 과정
    // 중복 집합이므로 교집합 되는 원소 개수에 유의하여 구함
    for (auto s1 : set1) {
        if (map2.find(s1) == map2.end())
            ;
        else if (map2[s1]) {
            map2[s1]--;
            u_set++;
        }
    }
    // 합집합 원소 개수를 구하는 과정
    // 중복 집합이므로 합집합 원소 개수에 유의하여 구함
    for (auto s2 : set2) {
        if (map1.find(s2) == map1.end())
            i_set++;
        else if (map1[s2])
            map1[s2]--;
        else
            i_set++;
    }
    return u_set / i_set * MULTIPLE;
}