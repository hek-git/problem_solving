#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (int i = 0; i < balls.size(); i++) {
        int d = 100000000;
        // ���� ����� �̿��ϴ� ���
        if (!(balls[i][1] == startY && startX > balls[i][0]))
            d = min(d, (int)pow(startY - balls[i][1], 2) + (int)pow(startX - (-balls[i][0]), 2));
        
        // �Ʒ��� ����� �̿��ϴ� ���
        if (!(balls[i][0] == startX && startY > balls[i][1]))
            d = min(d, (int)pow(startY - (-balls[i][1]), 2) + (int)pow(startX - balls[i][0], 2));
        
        // ������ ����� �̿��ϴ� ���
        if (!(balls[i][1] == startY && startX < balls[i][0]))
            d = min(d, (int)pow(balls[i][1] - startY, 2) + (int)pow(2 * m - balls[i][0] - startX, 2));

        // ���� ����� �̿��ϴ� ���
        if (!(balls[i][0] == startX && startY < balls[i][1]))
            d = min(d, (int)pow(2 * n - balls[i][1] - startY, 2) + (int)pow(balls[i][0] - startX, 2));
            
        answer.push_back(d);
    }
    return answer;
}