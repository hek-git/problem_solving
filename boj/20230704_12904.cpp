#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int ans = 0, i;
	string S, T;
	char a;
	cin >> S >> T;
	i = T.size() - 1;

	while (S.size() != T.size()) {
		if (T[i] == 'A') {
			T.erase(i);
		}
		else {
			T.erase(i);
			reverse(T.begin(), T.end());
		}
		i--;
	}

	cout << !T.compare(S);

}