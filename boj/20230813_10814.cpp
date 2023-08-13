#include <vector>
#include <string>
#include <tuple>
#include <iostream>

using namespace std;

int n, age;
string name;
tuple<int, int, string> sorted[100001];
vector<tuple<int, int, string>> v;

void merge(vector<tuple<int, int, string>>& n, int start, int mid, int end) {

    int i = start;
    int j = mid;
    int k = start;

    while (i < mid && j < end) {
        if (get<0>(n[i]) == get<0>(n[j])) {
            if (get<1>(n[i]) < get<1>(n[j]))
                sorted[k++] = n[i++];
            else
                sorted[k++] = n[j++];
        } else if (get<0>(n[i]) < get<0>(n[j]))
            sorted[k++] = n[i++];
        else
            sorted[k++] = n[j++];
    }

    while (i < mid) sorted[k++] = n[i++];
    while (j < end) sorted[k++] = n[j++];

    for (int a = start; a < end; a++) n[a] = sorted[a];

    // cout << '\n';
    // for (int i = 0; i < v.size(); i++) cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";
    // cout<< '\n';
}

void mergeSort(vector<tuple<int, int, string>>& n, int start, int end) {
    if (start + 1 < end) {
        mergeSort(n, start, (start + end) / 2);
        mergeSort(n, (start + end) / 2, end);
        merge(n, start, (start + end) / 2, end);
    }
}

int main() {
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> age >> name;      
        v.push_back(make_tuple(age, i, name));
    }

    mergeSort(v, 0, v.size());

    for (int i = 0; i < v.size(); i++) cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";

}