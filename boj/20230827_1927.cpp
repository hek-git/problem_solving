#include <iostream>

using namespace std;

int N, num, heap[200002];
int idx = 1;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void insert_max_heap(int num) {
    heap[idx] = num;
    int parent = idx / 2;
    int child = idx;

    while (parent) {
        if (heap[child] < heap[parent]) swap(heap[child], heap[parent]);
        child = parent;
        parent /= 2;
    }
    idx++;
}

int delete_min_heap() {
    if (idx == 1) return 0;
    int parent = 1;
    int child;
    int value = heap[1];
    heap[1] = heap[--idx];

    while (true) {
        if (heap[parent * 2] >= heap[parent * 2 + 1])
            child = parent * 2 + 1;
        else
            child = parent * 2;
        
        if(child >= idx) break;
        if (heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
        }
        parent = child;
    }
    return value;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == -1) {
            for (int j = 1; j <= 35; j++) {
                cout << heap[j] << " ";
            }
        } else if (num)
            insert_max_heap(num);
        else
            cout << delete_min_heap() << '\n';
    }
}