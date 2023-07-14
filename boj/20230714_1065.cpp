#include <iostream>
#include <vector>

using namespace std;

// �Ѽ����� Ȯ���ϴ� �Լ�
bool solution(int num) {
    vector<int> digit;
    int d1 = 0, d2 = 0;

    // 100 ���� ������ ���� ��� �Ѽ���(�� �ڸ��ų� ���ڸ��� ���� �ڸ����� �������� �� ���ڰ� �ϳ�, �ΰ��ε� �̴� ������ ���������̱� ����)
    if (num < 100) return true;

    // num�� 0�� �ƴҶ� ���� ���� �ڸ����� ���ϸ鼭 vector�� �߰��Ͽ� ������ ����
    while (num) {
        digit.push_back(num % 10);
        num /= 10;
    }

    // ������ ��ȸ�ϸ鼭 ������ �������� �Ǻ��Ѵ�(�� �ڸ��� ���� ������ ����Ƿ� �迭�� ���̴� �ּ� 3)
    for (int i = 2; i < digit.size(); i++) {
        d1 = digit[i - 1] - digit[i - 2];
        d2 = digit[i] - digit[i - 1];
        // ������ �ٸ��ٸ� �Ѽ��� �ƴϹǷ� false ��ȯ
        if (d1 != d2) return false;
    }
    // �����ϸ� �Ѽ��̹Ƿ� true ��ȯ
    return true;
}

int main() {

    // N���� ���ڸ� ��� �Ѽ��� ���س��� �Ѽ��� �ƴ� ���� ���� ������� ���� ����
    int N, ans;
    cin >> N;
    ans = N;

    // 1 ���� N���� �Լ��� �ݺ��ϸ� �Ѽ��� �ƴ϶�� ans 1����
    for (int i = 1; i <= N; i++) {
        if (!solution(i)) ans--;
    }
    cout << ans;
}