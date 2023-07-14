#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int N, num, stair[301];

// // ��������� ��� ������ ���ϴ� �Լ� point�� ����, step�� ��� ��, n�� ����� ���� ����ߴ���
// // ������ ���� �� ���, �� ����� �ö��� �� �޴� ��� ����� �� �� �ִ� ���� ���Ѵ�.
// // n���� ���� �� ����� �ö����� ����Ѵ�.(�ð� �ʰ�...)
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

// stair�� �� ����� ����
// point[N][i]�� N�� ���� �ö���µ� i ���� ����� �پ� �ö���� �� �޴� ������ �ִ밪
int N, num, stair[301], point[301][3];

int main() {
    // �Է�
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        stair[i] = num;
    }

    // �ʱ�� : 1���� ���������� 1�ܰ� �پ� �ö���� ���� �� �� ����
    // 2���� ���������� 2�ܰ� �پ� �ö������, 1������ 1�ܰ� �پ� �ö���� �� �� �� ����)
    point[1][1] = stair[1];
    point[2][1] = stair[2] + point[1][1];
    point[2][2] = stair[2];

    // 3������ �����ϰ� ������ ���� �����Ͽ� i-1������ 1����, i-2������ 2���� �پ� �ö���� �� ���� �� �ִ� �ִ� ������ ����
    // 1���� �پ� �ö���� ���� �ִ밪�� ���� �� ���� + �׳� 2���� �پ�ö� i-1 ������ �ö�� ������(���� ���� �� ���ӵ� 3 ���� �� �� ���� ����)
    // 2���� �پ� �ö���� ���� �ִ밪�� ���� �� ���� + max(1���� �پ�ö� i-2 ������ �ö�� ����, 2���� �پ�ö� i-2�� �ö�� ����)
    for (int i = 3; i <= N; i++) {
        point[i][1] = stair[i] + point[i - 1][2];
        point[i][2] = stair[i] + max(point[i - 2][1], point[i - 2][2]);
    }

    // N-1��° ������ 1���� �پ� �ö�� ������ N-2��° ������ 2���� �پ� �ö�� ���� �� �� ū ���� ��
    cout << max(point[N][1], point[N][2]);
}