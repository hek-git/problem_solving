#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

//스택 사용 x
// int main() {
//     int N, cnt, flag;
//     char c;

//     cin >> N;
//     getchar(); //버퍼(개행문자) 비우기

//     for (int i = 0; i < N; i++) {

//         cnt = 0, flag = 1;

//         vector<char> P;

//         while (true) {
//             //입력 받고 개행 문자일 경우 입력 중지
//             cin.get(c);
//             if (c == '\n') break;
//             P.push_back(c);
//         }

//         // ( 일 경우 )가 뒤에 하나 나와야 하므로 cnt 증가, ) 인 경우 cnt 감소
//         // cnt가 음수일 경우 )가 더 많이 나온 것이므로 올바르지 않음, NO 출력 후 break(다음 문자열로 넘어감)
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
//         // 종료후 cnt가 양수인 경우 ( 가 더 나온 것이므로 올바르지 않음, NO 출력후 다음 문자열로 넘어감
//         if (cnt > 0) {
//             cout << "NO" << endl;
//             continue;
//         }
//         //아무일도 일어나지 않은 경우 올바르므로 YES 출력
//         if (flag) cout << "YES" << endl;
//     }
// }

//스택 사용
int main() {
    int N, cnt, flag;
    char c;

    cin >> N;
    getchar(); //버퍼(개행문자) 비우기

    for (int i = 0; i < N; i++) {

        flag = 1;

        stack<char> s;

        while (true) {
            //입력 받고 개행 문자일 경우 입력 중지
            cin.get(c);
            if (c == '\n') break;
            
            //flag가 0 일 경우 이미 틀린 것이므로 입력만 받고 아무것도 하지 않음
            if(!flag) continue;

            // ( 일 경우 스택에 push
            // 아닐경우( ')' 인 경우 ) 스택에는 ( 만 있으므로 pop
            // 만약 스택이 비어있을 경우 == 앞에 ( 가 없는 경우이므로 틀림, flag를 0으로 바꾸고 ')'를 하나 push(빈 스택으로 만들지 않기 위함)
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

        // 입력이 끝나고 스택이 비어있지 않으면 ( 가 더 나왔거나 ) 하나 들어있는 경우이므로 틀림("NO") 출력
        if(!s.empty()){
            cout << "NO" << endl;
            continue;
        }
        //아무일도 발생하지 않은 경우(flag가 처음 값인 1인 경우) 정답("YES") 출력
        if(flag) cout << "YES" << endl;
    }
}