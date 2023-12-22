#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    string in;
    cin >> in;

    stack<char> s;


    for (char c : in) {
        if (c == '(') {
            s.push(c);
        }
        else {

            // If we've met ')' and stack is empty
            if (s.empty()) {
                cout << "false";
                return 0;
            }

            // Stack is non-empty
            s.pop();
        }
    }

    cout << ((s.empty()) ? "true" :  "false");
    return 0;
}
