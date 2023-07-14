#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

//���� ��� x
// int main() {
//     int N, cnt, flag;
//     char c;

//     cin >> N;
//     getchar(); //����(���๮��) ����

//     for (int i = 0; i < N; i++) {

//         cnt = 0, flag = 1;

//         vector<char> P;

//         while (true) {
//             //�Է� �ް� ���� ������ ��� �Է� ����
//             cin.get(c);
//             if (c == '\n') break;
//             P.push_back(c);
//         }

//         // ( �� ��� )�� �ڿ� �ϳ� ���;� �ϹǷ� cnt ����, ) �� ��� cnt ����
//         // cnt�� ������ ��� )�� �� ���� ���� ���̹Ƿ� �ùٸ��� ����, NO ��� �� break(���� ���ڿ��� �Ѿ)
//         for (auto p : P) {
//             if (p == '(')
//                 cnt++;
//             else
//                 cnt--;

//             if (cnt < 0) {
//                 cout << "NO" << endl;
//                 flag = 0;
//                 break;
//             }
//         }
//         // ������ cnt�� ����� ��� ( �� �� ���� ���̹Ƿ� �ùٸ��� ����, NO ����� ���� ���ڿ��� �Ѿ
//         if (cnt > 0) {
//             cout << "NO" << endl;
//             continue;
//         }
//         //�ƹ��ϵ� �Ͼ�� ���� ��� �ùٸ��Ƿ� YES ���
//         if (flag) cout << "YES" << endl;
//     }
// }

//���� ���
int main() {
    int N, cnt, flag;
    char c;

    cin >> N;
    getchar(); //����(���๮��) ����

    for (int i = 0; i < N; i++) {

        flag = 1;

        stack<char> s;

        while (true) {
            //�Է� �ް� ���� ������ ��� �Է� ����
            cin.get(c);
            if (c == '\n') break;
            
            //flag�� 0 �� ��� �̹� Ʋ�� ���̹Ƿ� �Է¸� �ް� �ƹ��͵� ���� ����
            if(!flag) continue;

            // ( �� ��� ���ÿ� push
            // �ƴҰ��( ')' �� ��� ) ���ÿ��� ( �� �����Ƿ� pop
            // ���� ������ ������� ��� == �տ� ( �� ���� ����̹Ƿ� Ʋ��, flag�� 0���� �ٲٰ� ')'�� �ϳ� push(�� �������� ������ �ʱ� ����)
            if (c == '('){
                s.push(c);
            } else{
                if(s.empty())
                {
                    flag=0;
                    s.push(c);
                }
                else s.pop();
            }           
        }

        // �Է��� ������ ������ ������� ������ ( �� �� ���԰ų� ) �ϳ� ����ִ� ����̹Ƿ� Ʋ��("NO") ���
        if(!s.empty()){
            cout << "NO" << endl;
            continue;
        }
        //�ƹ��ϵ� �߻����� ���� ���(flag�� ó�� ���� 1�� ���) ����("YES") ���
        if(flag) cout << "YES" << endl;
    }
}