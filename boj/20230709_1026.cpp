#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, num, ans=0;
	cin >> N;
	vector<int> A, B;
	for(int i=0; i<N; i++){
		cin >> num;
		A.push_back(num);
	}	
	
	for(int i=0; i<N; i++){
		cin >> num;
		B.push_back(num);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());

	for(int i=0; i<N; i++){
		ans+=A[i]*B[i];
	}
	cout << ans;
}
