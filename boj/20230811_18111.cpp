#include <iostream>

using namespace std;

int N, M, B, map[500][500];


int main() {

    cin >> N >> M >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            cin >> map[i][j];
        }
    }

}