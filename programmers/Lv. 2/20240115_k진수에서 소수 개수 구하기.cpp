#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

// 소수인지 판별하는 함수
bool is_prime(ll n) {
    if (n == 1) return false;
    ll m = (ll)sqrt(n);
    for (ll i = 2; i <= m; i++)
        if (n % i == 0) return false;
    return true;
}

// 10진수 n을 k 진법으로 변환
string formation_trans(int n, int k) {
    string s;
    while (n != 0) {
        s.push_back(n % k + '0');
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}

int solution(string num) {
    int cnt = 0, flag = 0;
    string tmp;

    // P인 경우를 찾는 구문
    if (num.find('0') == string::npos && is_prime(stoll(num))) cnt++;

    // 0P인 경우를 찾는 구문
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '0') break;
        tmp.push_back(num[i]);
    }
    if (tmp.size() != num.size() && is_prime(stoll(tmp))) cnt++;
    tmp.clear();

    // P0인 경우를 찾는 구문
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == '0') break;
        tmp.push_back(num[i]);
    }
    reverse(tmp.begin(), tmp.end());
    if (!tmp.empty() && tmp.size() != num.size() && is_prime(stoll(tmp))) cnt++;
    tmp.clear();

    // 0P0인 경우를 찾는 구문
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '0' && flag == 0)
            flag = 1;
        else if (num[i] == '0' && flag) {
            if (!tmp.empty()) {
                // cout << tmp << endl;
                if (is_prime(stoll(tmp))) cnt++;
                tmp.clear();
            }
        } else if (flag)
            tmp.push_back(num[i]);
    }

    return cnt;
}

int solution(int n, int k) {
    string num = formation_trans(n, k);
    return solution(num);
}