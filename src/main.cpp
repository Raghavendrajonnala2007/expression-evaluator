#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

// Check if a character is an operator
bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Check if a character is a digit
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Perform the calculation
int calculate(int left, int right, char op) {
    if (op == '+') return left + right;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    if (op == '/') return left / right;
    return 0;
}

// Determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix to Reverse Polish Notation (postfix)
vector<char> infixToRPN(const string& expression) {
    vector<char> output;
    stack<char> operators;

    for (char token : expression) {
        if (token == ' ') continue;

        if (isDigit(token)) {
            output.push_back(token);
        }
        else if (token == '(') {
            operators.push(token);
        }
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        }
        else if (isOperator(token)) {
            while (!operators.empty() &&
                   precedence(operators.top()) >= precedence(token) &&
                   operators.top() != '(') {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Pop remaining operators
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

// Evaluate RPN expression
int evalRPN(const string& rpn) {
    stack<int> s;
    string num;

    for (char ch : rpn) {
        if (isDigit(ch)) {
            num += ch;
        } else if (ch == ' ') {
            if (!num.empty()) {
                s.push(atoi(num.c_str()));
                num.clear();
            }
        } else if (isOperator(ch)) {
            if (!num.empty()) {
                s.push(atoi(num.c_str()));
                num.clear();
            }
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            int result = calculate(left, right, ch);
            s.push(result);
        }
    }

    return s.empty() ? 0 : s.top();
}

int main() {
    string infix = "2+2*(1*2-4/2)*1";
    vector<char> rpn = infixToRPN(infix);

    string rpnString;
    for (char ch : rpn) {
        cout << ch << ' ';
        rpnString += ch;
        rpnString += ' ';
    }

    cout << endl << "Result of RPN Evaluation: " << evalRPN(rpnString) << endl;

    return 0;
}
/* Use of this code:
Implements core data structures (stack, vector).

Demonstrates expression parsing, useful in real-world interpreters or calculators.

Clear structure with separated logic (conversion vs evaluation).*/