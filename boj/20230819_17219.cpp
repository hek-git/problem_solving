#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int N, M;
string site, passwd;
unordered_map<string, string> m;

int main() {

    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i<N; i++){
        cin >> site >> passwd;
        m[site] = passwd;
    }

    for(int i =0; i<M; i++){
        cin >> site;
        cout << m[site] << "\n";
    }

}