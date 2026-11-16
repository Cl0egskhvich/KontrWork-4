#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string word = "";
    string words[1000];
    int count = 0;

    cout << string(60, '-') << endl;

    for (int i = 0; i <= s.length(); i++) {
        if (i < s.length() && s[i] != ' ' && s[i] != ',' && s[i] != '.' &&
            s[i] != '!' && s[i] != '?') {
            word += s[i];
        }
        else {
            if (word != "") {
                bool found = false;

                for (int j = 0; j < count; j++) {
                    if (words[j] == word) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    words[count] = word;
                    count++;
                    cout << word << endl;
                }
                
                word = "";
            }
        }
    }

    return 0;
}
