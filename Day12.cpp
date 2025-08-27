#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    std::string s;
    std::cout << "Enter string: ";
    std::getline(std::cin, s);

    if (isValid(s))
        std::cout << "true\n";
    else
        std::cout << "false\n";
    return 0;
}