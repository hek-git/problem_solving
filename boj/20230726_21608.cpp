#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, ans, point[5];
int map[22][22], student, like[401][4], space[22][22], x[4] = { 0, 1, 0 ,-1 }, y[4] = { -1, 0, 1, 0 };
queue<int> q;

vector<pair<int, int>> CalculatePrefer(int s) {

	int max = 0;
	vector<pair<int, int>> candidate[5];
	vector<pair<int, int>> candidate_location;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int prefer_num = 0;
			
			if (map[i][j]) continue;

			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (map[i + y[k]][j + x[k]] == like[s][l]) prefer_num++;
				}
			}
			
			if (max <= prefer_num) {
				max = prefer_num;
				candidate[prefer_num].push_back(make_pair(i, j));
			}
			num = 0;
		}
	}

	for (int i = 0; i < candidate[max].size(); i++) {
		candidate_location.push_back(candidate[max][i]);
	}

	return candidate_location;
}

vector<pair<int, int>> CalculateSpace(vector<pair<int, int>>& c) {
	
	vector<pair<int, int>> candidate[5];
	vector<pair<int, int>> candidate_location;
	int max = 0;

	for (auto& a : c) {
		int space_num = space[a.first][a.second];
		if (max <= space_num) {
			max = space_num;
			candidate[space_num].push_back(make_pair(a.first, a.second));
		}
	}

	for (int i = 0; i < candidate[max].size(); i++) {
		candidate_location.push_back(candidate[max][i]);
	}
	return candidate_location;
}

pair<int, int> CalculateLocation(vector<pair<int, int>>& candidate) {
	
	sort(candidate.begin(), candidate.end());
	return candidate[0];
}

int CalculatePreferPoint(){

	int total_point = 0, prefer_num = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (map[i + y[k]][j + x[k]] == like[map[i][j]][l]) prefer_num++;
				}
			}
			total_point += point[prefer_num];
			prefer_num = 0;
		}
	}
	return total_point;
}

void Update(int a, int b) {
	
	space[a][b] = 0;

	for (int i = 0; i < 4; i++) {
		if (!space[a + y[i]][b + x[i]]) continue;
		else space[a + y[i]][b + x[i]]--;
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N*N; i++) {
		cin >> student;
		q.push(student);
		for (int j = 0; j < 4; j++) {
			cin >> like[student][j];
		}
	}

	// point ì´ˆê¸°?™”
	point[0] = 0;
	point[1] = 1;
	point[2] = 10;
	point[3] = 100;
	point[4] = 1000;
	
	for (int i = 0; i <= N+1; i++) {
		map[0][i] = -1;
		map[N+1][i] = -1;
		map[i][0] = -1;
		map[i][N+1] = -1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++) {
				if (!map[i + y[k]][j + x[k]]) space[i][j]++;
			}
		}
	}

	for (int i = 1; i <= N * N; i++) {

		vector<pair<int, int>> candidate;
		pair<int, int> location;

		student = q.front();
		q.pop();

		if (i == 1) {
			map[2][2] = student;
			Update(2, 2);
			continue;
		}

		candidate = CalculatePrefer(student);
		candidate = CalculateSpace(candidate);
		location = CalculateLocation(candidate);

		map[location.first][location.second] = student;
		Update(location.first, location.second);

	}
	cout << CalculatePreferPoint();
	return 0;
}