#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int N, start, fin, ans;
vector<pair<int, int>> p;

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start, &fin);
        p.push_back(make_pair(start, fin));
    }

    sort(p.begin(), p.end());

    // for (int i = 0; i < N; i++) {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    // cout <<endl << endl;

    ans = p[0].second - p[0].first;
    start = p[0].first;
    fin = p[0].second;

    for (int i = 1; i < N; i++) {

        if (p[i].first >= start && p[i].second <= fin){
            //cout << "角青1" << endl;
            continue;
        }
        else if (p[i].first < fin && p[i].second > fin) {
            start = fin;
            fin = p[i].second;
            //cout << "角青2" << endl;
        } else if (p[i].first >= fin) {
            start = p[i].first;
            fin = p[i].second;
            //cout << "角青3" << endl;
        } else continue;
        
        ans += (fin - start);

        //cout << i << "老 锭 " << ans << " " << start << " " << fin << endl;
    }

    printf("%d", ans);
}