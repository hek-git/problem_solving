#include <iostream>
#include <vector>

using namespace std;

// 한수임을 확인하는 함수
bool solution(int num) {
    vector<int> digit;
    int d1 = 0, d2 = 0;

    // 100 이전 까지의 수는 모두 한수임(한 자리거나 두자리의 경우는 자릿수로 나누었을 때 숫자가 하나, 두개인데 이는 무조건 등차수열이기 때문)
    if (num < 100) return true;

    // num이 0이 아닐때 까지 일의 자리부터 구하면서 vector에 추가하여 수열을 만듦
    while (num) {
        digit.push_back(num % 10);
        num /= 10;
    }

    // 수열을 순회하면서 등차가 동일한지 판별한다(세 자리수 부터 수열을 만드므로 배열의 길이는 최소 3)
    for (int i = 2; i < digit.size(); i++) {
        d1 = digit[i - 1] - digit[i - 2];
        d2 = digit[i] - digit[i - 1];
        // 등차가 다르다면 한수가 아니므로 false 반환
        if (d1 != d2) return false;
    }
    // 동일하면 한수이므로 true 반환
    return true;
}

int main() {

    // N개의 숫자를 모두 한수로 정해놓고 한수가 아닌 수를 빼는 방식으로 답을 구함
    int N, ans;
    cin >> N;
    ans = N;

    // 1 부터 N까지 함수를 반복하며 한수가 아니라면 ans 1감소
    for (int i = 1; i <= N; i++) {
        if (!solution(i)) ans--;
    }
    cout << ans;
}