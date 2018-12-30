#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

using namespace std;

bool isBalanced(string brackets)
{
    unordered_map<char, char> correspondence;
    correspondence['('] = ')';
    correspondence['['] = ']';
    correspondence['{'] = '}';

    stack<char> bracket_stack;

    for (int i = 0; i < brackets.length(); i++) {
        char current = brackets[i];
        if (current == '(' || current == '[' || current == '{') {
            bracket_stack.push(current);
        } else {
            if (bracket_stack.empty()) {
                return false;
            }
            char top = bracket_stack.top();
            bracket_stack.pop();
            if (current != correspondence[top]) {
                return false;
            }
        }
    }
    return bracket_stack.empty();
}

int main()
{
    string brackets = "([])[]({})";
    cout << isBalanced(brackets) << endl;
}