#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end()); 
    stack<char> st;
    string prefix = "";

    for (char &ch : infix) {
        if (isalnum(ch)) { 
            prefix += ch;
        } else if (ch == ')') {
            st.push(ch);
        } else if (ch == '(') {
            while (!st.empty() && st.top() != ')') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } else { 
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;
    return 0;
}
