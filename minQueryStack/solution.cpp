#include <iostream>
#include <stack>

using namespace std;

int main() {
    

    stack<int> currElements, minTillNow;

    while(true) {
        int num;
        /*
         * add - Expect a number which to add to first stack
         * sub - Pop last num from first stack (And eventually update minStack
         * if needed)
         * min - Return minimum number till now
         */
        string op;
        cin >> num;
        
        if (op == "add") {
            currElements.push(num);

            if (num < minTillNow.top()) {
                minTillNow.push(num);
            }

        }
        else if (op == "sub") {

            if (currElements.empty()) {
                cout << "No elements in stack!\n";
                continue;
            }

            int currTop = currElements.top();

            if (currTop == minTillNow.top()) {
                minTillNow.pop();
            }

            currElements.pop();
        }
        else {
            if (minTillNow.empty()){
                continue;
            }

            cout << minTillNow.top() << '\n';
        }

        if (! minTillNow.empty() && num < minTillNow.top()) {
            minTillNow.push(num);
        }
        currElements.push(num);
    }
}
