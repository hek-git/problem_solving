#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, ans;
string word;

// 그룹 단어인지 확인하는 함수(맞을 경우 true, 아닐 경우 false 반환)
// 단어에서 나오는 철자들을 보관할 alphabet 배열
// 바로 이전의 철자를 보관할 prev

bool checker() {
	
	vector<char> alphabet;
	char prev = word[0];
	alphabet.push_back(word[0]);

	// 단어의 각 철자를 순회하면서
	for (auto w : word) {
		
		int flag = 0;
		
		// 철자가 이전에 존재했던 것이라면 flag 세팅
		for (auto a : alphabet) if (a == w) flag = 1;
		
		// 바로 이전의 철자가 다르면서 기존에 나온 철자라면(flag==1) 떨어져서 나타난 철자이므로 그룹단어가 아님
		if (flag && prev != w) return false;

		// 이전에 존재하지 않았던 철자라면 alphabet 배열에 추가
		else if(flag == 0) alphabet.push_back(w);

		// 현재 철자가 다음 철자의 이전 철자가 되므로 이전 철자(prev) 업데이트
		prev = w;

	}

	return true;

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		//checker 함수가 true인 경우 그룹 단어이므로 ans 증가
		if (checker()) ans++;
	}

	cout << ans;

}
