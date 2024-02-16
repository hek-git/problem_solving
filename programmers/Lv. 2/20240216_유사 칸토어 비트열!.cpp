#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int bit[2][5] = {{0, 0, 0, 0, 0}, {1, 1, 0, 1, 1}}, cnt[2][5] = {{0, 0, 0, 0, 0}, {1, 2, 2, 3, 4}};


int left_bit(int n, ll r){
    if(n == 1) return bit[1][r];
    return bit[left_bit(n - 1, r / 5)][r % 5];
}

int solution(int n, ll r) {
    if(n == 1) return cnt[1][r];
    return solution(n - 1, r / 5 - 1) * 4 + cnt[left_bit(n - 1, r / 5)][r % 5];
}

int solution(int n, long long l, long long r) {
    return solution(n, r - 1) - solution(n, l - 2);
}