#include <iostream>
#include <vector>

using namespace std;

int main() {
	//준현이와 성민이의 fisrt는 보유한 돈, seconds는 보유한 주식 수
	int money, up = -1, down = -1, num;
	pair<int, int> jun, sung;
	vector<int> stock(15, 0);
	cin >> money;
	jun.first = sung.first = money;
	
	for (int i = 1; i < 15; i++) {
		cin >> num;
		stock[i] = num;
	}

	for (int i = 1; i < 15; i++) {
		//준현의 매매법
		if (jun.first >=  stock[i]) {
			jun.second += jun.first / stock[i];
			jun.first = jun.first % stock[i];
		}
		//성민의 매매법
		if (stock[i - 1] < stock[i]) {
			up++;
			down = 0;
		}
		else if (stock[i - 1] > stock[i]) {
			down++;
			up = 0;
		}
		else up = 0, down = 0;

		if (up >= 3 && sung.second) {
			sung.first = sung.second * stock[i];
			sung.second = 0;
		}
		else if (down >= 3) {
			sung.second += sung.first / stock[i];
			sung.first = sung.first % stock[i];
		}
	}
	//cout << jun.first + jun.second * stock[14] << " " << sung.first + sung.second * stock[14] << endl ;
	if (jun.first + jun.second * stock[14] > sung.first + sung.second * stock[14]) cout << "BNP";
	else if (jun.first + jun.second * stock[14] < sung.first + sung.second * stock[14]) cout << "TIMING";
	else cout << "SAMESAME";
	
}
