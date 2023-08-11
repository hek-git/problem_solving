#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int n, m, num;
vector<int> v;

bool binarySearch(int num) {

    int left = 0, right = n-1, mid = 0;

    while(left <= right){
        mid = (left+right)/2;
        if(v[mid] == num) return true;
        else if(v[mid] > num) right = mid-1;
        else left = mid+1;
    }

    return false;
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        printf("%d\n", binarySearch(num));
    }
}