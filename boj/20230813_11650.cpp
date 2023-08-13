#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
pair<int, int> sorted[100001];
vector<pair<int, int>> v;

void merge(vector<pair<int, int>>& n, int start, int mid, int end) {
    int i = start;
    int j = mid;
    int k = start;

    while (i < mid && j < end) {
        if (n[i].first == n[j].first) {
            if (n[i].second < n[j].second)
                sorted[k++] = n[i++];
            else
                sorted[k++] = n[j++];
        } else if (n[i].first < n[j].first)
            sorted[k++] = n[i++];
        else
            sorted[k++] = n[j++];
    }

    while (i < mid) sorted[k++] = n[i++];
    while (j < end) sorted[k++] = n[j++];

    for (int a = start; a < end; a++) n[a] = sorted[a];
}

void mergeSort(vector<pair<int, int>>& n, int start, int end) {
    if (start + 1 < end) {
        mergeSort(n, start, (start + end) / 2);
        mergeSort(n, (start + end) / 2, end);
        merge(n, start, (start + end) / 2, end);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }

    mergeSort(v, 0, v.size());

    for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
}