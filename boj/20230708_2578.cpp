#include <iostream>
#include <vector>

using namespace std;

int bingo[6][6], num[26], bingo_cnt;

// �������� Ȯ���ϴ� �Լ�
void check_bingo(int a, int b) {

	int flag=0;

    //������ Ȯ��
	for (int i = 1; i < 6; i++) {
        if (bingo[i][b]) break;
	    flag++;
    }
	
	if(flag == 5) bingo_cnt++;
	flag=0;

	//������ Ȯ��
    for (int i = 1; i < 6; i++) {
        if (bingo[a][i]) break;
        flag++;
    }

	if(flag == 5) bingo_cnt++;
	flag=0;

	//���� �밢�� Ȯ��
    if (a == b) {
        for (int i = 1; i < 6; i++) {
            if (bingo[i][i]) break;
            flag++;
        }
    }

	if(flag == 5) bingo_cnt++;
	flag=0;
	
	//������ �밢�� Ȯ��
    if (a + b == 6) {
        for (int i = 1; i < 6; i++) {
            if (bingo[i][6 - i]) break;
            flag++;
        }
    }

	if(flag == 5) bingo_cnt++;
	
}

    int main() {
        int n;
        pair<int, int> pos[26];

        // �Է�
        for (int i = 1; i < 6; i++) {
            for (int j = 1; j < 6; j++) {
                cin >> n;
                bingo[i][j] = n;
                pos[n].first = i;
                pos[n].second = j;
            }
        }

        // ��ȸ�� �Է�
        for (int i = 1; i < 26; i++) {
            cin >> n;
            num[i] = n;
        }

        // ��ȸ�ڰ� �θ� ������ ��ȸ�ϸ� �������� �Ǻ�
        for (int i = 1; i < 26; i++) {
            int a = pos[num[i]].first, b = pos[num[i]].second;
            bingo[a][b] = 0;
            check_bingo(a, b);
            if (bingo_cnt >= 3) {
                cout << i;
                break;
            }
        }
    }
