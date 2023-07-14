#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int N, num, stair[301];

// // 재귀적으로 계단 점수를 구하는 함수 point는 점수, step은 계단 수, n은 계단을 연속 몇번했는지
// // 시작점 부터 한 계단, 두 계단을 올라갔을 때 받는 모든 경우의 수 중 최대 값을 구한다.
// // n으로 연속 몇 계단을 올랐는지 계산한다.(시간 초과...)
// int solution(int point, int step, int n) {
//     if (step > N) return point;
//     if (n == 2) return solution(point + stair[step], step + 2, 1);
//     return max(solution(point + stair[step], step + 2, 1), solution(point + stair[step], step + 1, n + 1));
// }

// int main() {
//     cin >> N;

//     for (int i = 1; i <= N; i++) {
//         cin >> num;
//         stair[i] = num;
//     }
//     cout << solution(0, 0, 0);
// }

// stair은 각 계단의 점수
// point[N][i]는 N층 까지 올라오는데 i 개의 계단을 뛰어 올라왔을 때 받는 점수의 최대값
int N, num, stair[301], point[301][3];

int main() {
    // 입력
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        stair[i] = num;
    }

    // 초기식 : 1층은 시작점에서 1단계 뛰어 올라왔을 때만 올 수 있음
    // 2층은 시작점에서 2단계 뛰어 올라왔을때, 1층에서 1단계 뛰어 올라왔을 때 올 수 있음)
    point[1][1] = stair[1];
    point[2][1] = stair[2] + point[1][1];
    point[2][2] = stair[2];

    // 3층부터 시작하고 이전의 답을 참고하여 i-1층에서 1걸음, i-2층에서 2걸음 뛰어 올라왔을 때 받을 수 있는 최대 점수를 구함
    // 1걸음 뛰어 올라왔을 때의 최대값은 현재 층 점수 + 그냥 2걸음 뛰어올라 i-1 층으로 올라온 점수임(문제 조건 상 연속된 3 층을 뛸 수 없기 때문)
    // 2걸음 뛰어 올라왔을 때의 최대값은 현재 층 점수 + max(1걸음 뛰어올라 i-2 층으로 올라온 점수, 2걸음 뛰어올라 i-2층 올라온 점수)
    for (int i = 3; i <= N; i++) {
        point[i][1] = stair[i] + point[i - 1][2];
        point[i][2] = stair[i] + max(point[i - 2][1], point[i - 2][2]);
    }

    // N-1번째 층에서 1걸음 뛰어 올라온 점수와 N-2번째 층에서 2걸음 뛰어 올라온 점수 중 더 큰 값이 답
    cout << max(point[N][1], point[N][2]);
}