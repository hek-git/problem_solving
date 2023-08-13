#include <iostream>
#include <string>

using namespace std;

string s;
int ans;

int main() {
	
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (i == 0);
			else ans++;
		}
	}
	ans++;
	if (s[s.size() - 1] == ' ') ans--;
	cout << ans;
}