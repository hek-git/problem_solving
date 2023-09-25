#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

// map¿∏∑Œ «¨ «Æ¿Ã
// int T, k, n;
// map<int, int> q;
// char cmd;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> T;
//     for (int i = 0; i < T; i++) {
//         q.clear();
//         cin >> k;

//         for (int j = 0; j < k; j++) {
//             cin >> cmd >> n;

//             if (cmd == 'I') {
//                 if (q.find(n) != q.end())
//                     q[n]++;
//                 else
//                     q[n] = 1;
//             } else {
//                 if (!q.empty()) {
//                     if (n == -1) {
//                         if ((*q.begin()).second > 1)
//                             (*q.begin()).second--;
//                         else
//                             q.erase(q.begin());
//                     } else {
//                         if ((*q.rbegin()).second > 1) (*q.rbegin()).second--;
//                         else q.erase(--q.end());
//                     }
//                 }
//             }
//         }

//         if (!q.empty())
//             cout << (*q.rbegin()).first << " " << (*q.begin()).first << '\n';
//         else
//             cout << "EMPTY\n";
//     }
// }

long long T, k, n, capacity;
char cmd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        set<long long> max_set, min_set;
        priority_queue<long long> min_heap, max_heap;
        
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> cmd >> n;
            if (cmd == 'I') {
                min_heap.push(-n);
                max_heap.push(n);
                capacity++;
            } else {
                if(!capacity) continue;
                if (n == 1 && !max_heap.empty()) {
                    while(min_set.find(max_heap.top()) != min_set.end()){
                        min_set.erase(max_heap.top());
                        max_heap.pop();
                    }
                    max_set.insert(max_heap.top());
                    max_heap.pop();
                } else if(n== -1 && !min_heap.empty()) {
                    while(!max_set.empty() && max_set.find(-min_heap.top()) != max_set.end()){
                        max_set.erase(-min_heap.top());
                        min_heap.pop();
                    }
                    min_set.insert(-min_heap.top());
                    min_heap.pop();
                }
                capacity--;
            }
        }

        cout << "min heap ";
        while(!min_heap.empty()){
            cout << min_heap.top() << " ";
            min_heap.pop();
        }
        cout << endl;

        cout << "max heap ";
        while(!max_heap.empty()){
            cout << max_heap.top() << " ";
            max_heap.pop();
        }
        cout << endl;
        
        //if(min_heap.empty() || max_heap.empty()) cout << "EMPTY\n";
        //else cout << max_heap.top() << " " << -min_heap.top() << "\n";
    }
}