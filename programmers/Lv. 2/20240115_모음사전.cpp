#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt, answer;
char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
string s;

void dictionary(string& word){
    if(!s.compare(word)){
        answer = cnt;
        return;
    }
    if(s.size() == 5) return;

    for(int i = 0; i < 5; i++){
        s.push_back(alphabet[i]);
        cnt++;
        dictionary(word);
        s.pop_back();
    }
}

int solution(string word) {
    dictionary(word);
    return answer;
}

int main(){
    solution("AAAAA");
}