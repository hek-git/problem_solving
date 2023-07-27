#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct card {
    char color;
    int num;
};

vector<card> c(5);
int card_num[10];
char color;
int num;

int first() {
    for (int i = 1; i < 5; i++) {
        if (c[i].num - c[i - 1].num != 1 || c[i].color != c[i - 1].color) return 0;
    }
    return 900 + c[4].num;
}

int second() {
    for (int i = 0; i < 10; i++) {
        if(card_num[i] == 4) return i + 800;
    }
    return 0;
}

int third() {
    int three = 0, two = 0;
    for (int i = 0; i < 10; i++) {
        if(card_num[i] == 3) three = i;
        if(card_num[i] == 2) two = i;
    }
    if(three && two) return 10*three + two + 700;
    else return 0;
}

int fourth() {
    for (int i = 1; i < 5; i++) {
        if (c[i].color != c[i - 1].color) return 0;
    }
    return 600 + c[4].num;
}

int fifth() {
    for (int i = 1; i < 5; i++) {
        if (c[i].num - c[i - 1].num != 1) return 0;
    }
    return 500 + c[4].num;
}

int sixth() {
    for (int i = 0; i < 10; i++) {
        if(card_num[i] == 3) return i + 400;
    }
    return 0;
}

int seventh() {
    vector<int> p;    
    for (int i = 9; i > 0; i--) {
        if(card_num[i] == 2) p.push_back(i);
    }
    if(p.size() == 2) return p[0] * 10 + p[1] + 300;
    else return 0;
}

int eighth() {
    for (int i = 0; i < 10; i++) {
        if(card_num[i] == 2) return i + 200;
    }
    return 0;
}

int ninth() {
    return c[4].num + 100;
}

bool compare(card a, card b) {
    if (a.num == b.num) {
        return a.color < b.color;
    }
    return a.num < b.num;
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> color >> num;

        c[i].color = color;
        c[i].num = num;
    }

    sort(c.begin(), c.end(), compare);

    for(int i=0; i<5; i++){
        card_num[c[i].num]++;
    }
    
    if (first())
        cout << first();
    else if (second())
        cout << second();
    else if (third())
        cout << third();
    else if (fourth())
        cout << fourth();
    else if (fifth())
        cout << fifth();
    else if (sixth())
        cout << sixth();
    else if (seventh())
        cout << seventh();
    else if (eighth())
        cout << eighth();
    else
        cout << ninth();
}