#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student{
public:
    int d;
    int m;
    int y;
    string name;

    Student(string name, int d, int m, int y){
        this->name = name;
        this->d = d;
        this->m =m;
        this->y = y;
    }
};

int N, d, m, y;
string name;
vector<Student> s;

bool cmp(Student& s1, Student& s2){
    if(s1.y == s2.y){
        if(s1.m == s2.m){
            return s1.d > s2.d;
        }
        return s1.m > s2.m;
    }
    return s1.y > s2.y; 
}

int main() {
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> name >> d >> m >> y;
        s.push_back(Student(name, d, m, y));
    }
    sort(s.begin(), s.end(), cmp);
    cout << s[0].name << endl << s[N-1].name;
}