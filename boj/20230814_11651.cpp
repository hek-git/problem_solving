#include <cstdio>
#include <vector>

using namespace std;

int n, a, b;
vector<pair<int, int>> v(100001);
vector<pair<int, int>> sorted(100001);

void merge(int begin, int end){

    int mid = (begin + end) / 2;
    int i = begin;
    int j = mid;
    int k = begin;

    while(i < mid && j < end){
        if(v[i].second == v[j].second){
            if(v[i].first < v[j].first) sorted[k++] = v[i++];
            else sorted[k++] = v[j++];
        }else{
            if(v[i].second < v[j].second) sorted[k++] = v[i++];
            else sorted[k++] = v[j++];
        }
    }

    while(i < mid) sorted[k++] = v[i++];
    while(j < end) sorted[k++] = v[j++];

    for(int i = begin; i < end; i++) v[i] = sorted[i];
    
}

void mergeSort(int begin, int end){
    if(begin + 1 < end){
        mergeSort(begin, (begin + end) / 2);
        mergeSort((begin + end) / 2, end);
        merge(begin, end);
    }
}

int main() {

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &a, &b);
        v[i] = make_pair(a, b);
    }

    mergeSort(0, n);
    for (int i = 0; i < n; i++) printf("%d %d\n", v[i].first, v[i].second);
}