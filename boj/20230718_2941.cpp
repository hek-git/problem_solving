#include <iostream>
#include <string>

using namespace std;

int ans, i;
string word;

int main() {
    cin >> word;

    while (i < word.size()) {
        if (i == word.size() - 1) {
            ans++;
            break;
        }
        switch (word[i]) {
            case 'c':
                if (word[i + 1] == '=' || word[i + 1] == '-') i++;
                ans++;
                break;

            case 'd':
                if (word[i + 1] == 'z') {
                    if (i < word.size() - 2 && word[i + 2] == '=')
                        i += 2;
                    else {
                        i++;
                        ans++;
                    }
                } else if (word[i + 1] == '-')
                    i++;
                ans++;
                break;

            case 'l':
                if (word[i + 1] == 'j') i++;
                ans++;
                break;

            case 'n':
                if (word[i + 1] == 'j') i++;
                ans++;
                break;

            case 's':
                if (word[i + 1] == '=') i++;
                ans++;
                break;

            case 'z':
                if (word[i + 1] == '=') i++;
                ans++;
                break;

            default:
                ans++;
        }
        i++;
    }

    cout << ans;
}