#include <iostream>
#include <string>

using namespace std;

int ans, i;
string word;

int main() {
    
    cin >> word;

    while(i < word.size()-1){
        switch(word[i]){
            case 'c':
                if(word[i+1]=='=') ans++;
                
        }
    }
    

}