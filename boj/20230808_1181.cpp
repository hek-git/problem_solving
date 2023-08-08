#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
vector<string> word;
unordered_set<string> s;

bool cmp(string& s1, string& s2){
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		if (s.find(tmp) != s.end()) continue;
		s.insert(tmp);
		word.push_back(tmp);
	}

	sort(word.begin(), word.end(), cmp);

	for (auto a : word) {
		cout << a << endl;
	}

	
}