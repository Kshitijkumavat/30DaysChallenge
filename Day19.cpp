#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

int evalPostfix(const std::string& expr) {
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b); 
            else if (token == "^") st.push(static_cast<int>(std::pow(a, b)));
        } else {
            st.push(std::stoi(token));
        }
    }
    return st.top();
}

int main() {
    std::string expr;
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, expr);
    std::cout << evalPostfix(expr) << std::endl;
    return 0;
}