#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, ans = -200;

int main() {
    
    cin >> a >> b >> c;

    ans = max(c, (max(b, max(a, ans))));
    cout << ans;
    return 0;
}