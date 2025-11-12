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



⚙️ Main Idea

It uses a stack to keep track of opening brackets —
when a closing bracket appears, it checks if it matches the last opening one.

🧩 Step-by-Step Logic

Start

Input an expression (string with brackets).

For each character in the string:

If it’s an opening bracket (, {, or [,
→ push it onto the stack.

If it’s a closing bracket ), }, or ]:
→ Check if the stack is empty (no opening bracket to match) → ❌ not balanced.
→ Pop the top element and compare:

If they don’t form a correct pair → ❌ not balanced.

After checking all characters:

If the stack is empty → ✅ All brackets matched → Balanced.

If not → ❌ Some opening brackets left → Not Balanced.

🖥️ Output

✅ “Expression is well parenthesized.” → if brackets are balanced.

❌ “Expression is NOT well parenthesized.” → if mismatched or missing.

⏱️ Time Complexity

O(n) → Each character is processed once.
