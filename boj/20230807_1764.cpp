#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string> h, s, ans;
string name;
int N, M;

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		h.insert(name);

	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		s.insert(name);
	}
	for (auto a : h) {
		if (s.find(a) != s.end()) ans.insert(a);
	}

	cout << ans.size() << endl;
	for (auto a : ans) cout << a << endl;
	
}