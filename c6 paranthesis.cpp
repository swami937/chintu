#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& exp) {
    stack<char> s;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Expression is well parenthesized.\n";
    else
        cout << "Expression is NOT well parenthesized.\n";

    return 0;
}
