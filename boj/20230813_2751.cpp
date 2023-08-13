#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, num, sorted[1000001];
vector<int> v;

void merge(vector<int>& n, int start, int mid, int end) {
    
    int i = start;
    int j = mid;
    int k = start;

    while(i < mid && j < end){
        if(n[i] < n[j]) sorted[k++] = n[i++];
        else sorted[k++] = n[j++];
    }

    while(i < mid) sorted[k++] = n[i++];
    while(j < end) sorted[k++] = n[j++];

    for(int a=start; a<end; a++) n[a] = sorted[a];
}

void mergeSort(vector<int>& n, int start, int end) {

    if (start + 1 < end) {
        mergeSort(n, start, (start + end) / 2);
        mergeSort(n, (start + end) / 2, end);
        merge(n, start, (start + end) / 2, end);
    }
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    v.push_back(num);
    }

    mergeSort(v, 0, v.size());

    for (int i = 0; i < v.size(); i++) printf("%d\n", v[i]);
}