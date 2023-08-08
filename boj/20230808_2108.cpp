#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, num;
int median, most, range, cnt = 1, sum, average;
vector<int> candidate, v;

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
		sum += num;
	}

	if(N != 1) sort(v.begin(), v.end());

	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) cnt++;
		else {
			most = max(most, cnt);
			cnt = 1;
		}
	}
	most = max(most, cnt);

	cnt = 1;
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) cnt++;
		else {
			if (cnt == most) {
				candidate.push_back(v[i - 1]);
			}
			cnt = 1;
		}
	}

	if (cnt == most) candidate.push_back(v[N - 1]);

	average = round(double(sum) / N);
	median = v[N / 2];
	range = v[N - 1] - v[0];

	if (candidate.size() > 1) most = candidate[1];
	else most = candidate[0];

	printf("%d\n%d\n%d\n%d", average, median, most, range);

	
	
}