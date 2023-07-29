#include <iostream>
#include <vector>

using namespace std;

int N, x, y, ans;
vector<pair<int, int>> people;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        people.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++) {
        ans = 1;
        for (int j = 0; j < N; j++) {
            if(people[i].first < people[j].first && people[i].second < people[j].second) ans++;
        }
        cout << ans << " ";
    }
}