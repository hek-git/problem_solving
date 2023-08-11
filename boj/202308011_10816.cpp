#include <cstdio>
#include <map>

using namespace std;

int N, M, num;
map<int, int> m;


int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        if(m.find(num) == m.end()) m[num] = 1;
        else m[num]++;
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &num);
        if(m.find(num) == m.end()) printf("0 ");
        else printf("%d ", m[num]); 
    }
    
}