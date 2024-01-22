#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer[60001];
    answer[1] = 1;
    answer[2] = 2;
    for (int i = 3; i <= 60000; i++) {
        answer[i] = ((answer[i - 1] % MOD) + (answer[i - 2] % MOD)) % MOD;
    }
    return answer[n];
}