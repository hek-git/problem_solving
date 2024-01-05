#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a > b) swap(a, b);
    cout << "a : " << a << " b : " << b << endl;
    while (true)
    {
        if((b - a) == 1 && b % 2 == 0 && a % 2 == 1) break;
        answer++;
        if (a % 2 == 1)
            a = a / 2 + 1;
        else
            a /= 2;

        if (b % 2 == 1)
            b = b / 2 + 1;
        else
            b /= 2;
        cout << "a : " << a << " b : " << b << endl;
    }

    return answer;
}