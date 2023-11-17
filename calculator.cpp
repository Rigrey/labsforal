// Copyright 2023 <Michail Ozhogin>

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

double calculate(const string& expression) {
  stack<double> numbers;
  stack<char> ops;
  istringstream iss(expression);
  char token;
  double number;
  double sign = 1;
  while (iss >> token) {
    if (isdigit(token)) {
      iss.putback(token);
      iss >> number;
      numbers.push(sign * number);
      sign = 1;
    } else if (token == '(') {
      ops.push(token);
    } else if (token == ')') {
      while (!ops.empty() && ops.top() != '(') {
        double b = numbers.top();
        numbers.pop();
        double a = numbers.top();
        numbers.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+') {
          numbers.push(a + b);
        } else if (op == '-') {
          numbers.push(a - b);
        } else if (op == '*') {
          numbers.push(a * b);
        } else if (op == '/') {
          numbers.push(a / b);
        }
      }
      ops.pop();
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      if (token == '-' && (isdigit(iss.peek()))) {
        sign = -1;
        continue;
      }
      while (!ops.empty() && ops.top() != '(' &&
             ((token == '+' || token == '-') ||
              (ops.top() == '*' || ops.top() == '/'))) {
        double b = numbers.top();
        numbers.pop();
        double a = numbers.top();
        numbers.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+') {
          numbers.push(a + b);
        } else if (op == '-') {
          numbers.push(a - b);
        } else if (op == '*') {
          numbers.push(a * b);
        } else if (op == '/') {
          numbers.push(a / b);
        }
      }
      ops.push(token);
    }
  }
  while (!ops.empty()) {
    double b = numbers.top();
    numbers.pop();
    double a = numbers.top();
    numbers.pop();
    char op = ops.top();
    ops.pop();
    if (op == '+') {
      numbers.push(a + b);
    } else if (op == '-') {
      numbers.push(a - b);
    } else if (op == '*') {
      numbers.push(a * b);
    } else if (op == '/') {
      numbers.push(a / b);
    }
  }
  return numbers.top();
}

int main(int argc, char* argv[]) {
  string expression = argv[1];
  double result = calculate(expression);
  cout << "Result: " << result << endl;
  return 0;
}
