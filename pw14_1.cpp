
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "no";
                return 0;
            }

            char top = st.top();

            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            }
            else {
                cout << "no";
                return 0;
            }
        }
    }

    if (st.empty()) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}
