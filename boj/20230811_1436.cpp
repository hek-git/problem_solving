#include <iostream>
#include <string>

using namespace std;

int n, num = 666, ans, cmp =1;

int main() {
	
	cin >> n;

	while(cmp != n){
		num++;
		string s = to_string(num);
		if(s.find("666") != string::npos) cmp++;
	}
	
	cout << num;
}