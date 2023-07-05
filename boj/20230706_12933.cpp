#include <iostream>
#include <vector>
#include <string>

using namespace std;

//오리 수를 세는 함수
int count_duck(string& s) {
	//u, a, c, k이 나올 수 있는 횟수를 저장하는 vector
	//오리 수는 line sweeping으로 센다 
	//문자열 길이가 5의 배수가 아닌 경우와
	//각 반복 종료시 vector의 원소가 하나라도 0보다 작은 경우 나오면 안되는 문자이므로 잘못됨(-1) 반환
	vector<int> p(4, 0);
	int ans=0, tmp=0;

	if (s.size() % 5 != 0) return -1;

	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'q':
			p[0]++;
			tmp++;
			break;

		case 'u':
			p[0]--;
			p[1]++;
			break;

		case 'a':
			p[1]--;
			p[2]++;
			break;

		case 'c':
			p[2]--;
			p[3]++;
			break;

		case 'k':
			p[3]--;
			tmp--;
			break;
		}

		//u, a, c, k 중 하나가 초과해서 나온 경우
		if (p[0] < 0 || p[1] < 0 || p[2] < 0 || p[3] < 0) return -1;

		//현재 울고 있는 오리의 수
		if (ans < tmp)	ans = tmp;

	}
	//오리가 울다 만 경우 ex) quackqqqqq, qqqqquuuuu
	if (p[0] > 0 || p[1] > 0 || p[2] > 0 || p[3] > 0) return -1;
	return ans;
}

int main() {

	string s;
	cin >> s;

	cout << count_duck(s);

}
