#include <iostream>

using namespace std;

int N;
char root, l, r;
pair<int, int> Tree[27];

void preorder(int root) {
    cout << (char)(root + 'A' - 1);
    if(Tree[root].first) preorder(Tree[root].first);
    if(Tree[root].second) preorder(Tree[root].second);
}

void inorder(int root) {
    if(Tree[root].first) inorder(Tree[root].first);
    cout << (char)(root + 'A' - 1);
    if(Tree[root].second) inorder(Tree[root].second);
}

void postorder(int root) {
    if(Tree[root].first) postorder(Tree[root].first);
    if(Tree[root].second) postorder(Tree[root].second);
    cout << (char)(root + 'A' - 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> root >> l >> r;
        if (l != '.') Tree[root - 'A' + 1].first = l - 'A' + 1;
        if (r != '.') Tree[root - 'A' + 1].second = r - 'A' + 1;
    }

    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
}