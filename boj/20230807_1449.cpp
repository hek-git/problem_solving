#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, num, ans;
double start, fin, L, l;
vector<int> v;

int main() {

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	start = v[0] - 0.5;
	fin = start + L;
	ans++;
	
	for (int i= 0; i < N; i++) {
		
		start = v[i] - 0.5;
		if (v[i] < fin) {
			continue;
		}
		else {
			fin = start + L;
			ans++;
		}
	}

	cout << ans;
}