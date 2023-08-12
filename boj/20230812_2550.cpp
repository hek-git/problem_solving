#include <iostream>

using namespace std;

int N, M, B, map[500][500];


int main() {

    cin >> N >> M >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            cin >> map[i][j];#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<int> v;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    
    cin >> n;

    for(int i=0; i<n ;i++){
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < v.size(); i++) {

        int j = i;

        while (j > 0 && v[j - 1] > v[j]) {
            swap(v[j-1], v[j]);
            j--;
        }
    }

    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}
        }
    }

}