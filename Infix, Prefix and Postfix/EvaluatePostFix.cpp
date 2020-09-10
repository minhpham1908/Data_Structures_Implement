#include "Header.h"
using std::string;
using std::stack;

int EvaluatePostFix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char c);
bool IsNumber(char c);

//int main() {
	/*string expression("2 3 + 42 90 - * 9 -");
	int result = EvaluatePostFix(expression);
	std::cout << "Result: " << result << std::endl;
	std::cout << "Result: " << EvaluatePostFix("1 2 +") << std::endl;
	std::cout << "Result: " << EvaluatePostFix("3 2 -") << std::endl;
	std::cout << "Result: " << EvaluatePostFix("12 2 *") << std::endl;
	std::cout << "Result: " << EvaluatePostFix("12 2 /") << std::endl;*/
	
//}

int EvaluatePostFix(string expression) {
	stack<int> stack;
	for (string::size_type i = 0; i < expression.length(); ++i) {
		if (expression[i] == ' ') continue;
		else if (IsNumber(expression[i])) {
			int operand = 0;
			while (i < expression.length() && IsNumber(expression[i])) {
				operand = expression[i] - '0' + (operand * 10);
				i++;
			}
			i--;
			stack.push(operand);
		}
		else if (IsOperator(expression[i])) {
			int op2 = stack.top(); stack.pop();
			int op1 = stack.top(); stack.pop();
			stack.push(PerformOperation(expression[i], op1, op2));
		}
	}
	return stack.top();
}

int PerformOperation(char operation, int op1, int op2) {
	if (operation == '+') {
		return op1 + op2;
	}
	else if (operation == '-') {
		return op1 - op2;
	}
	else if (operation == '*') {
		return op1 * op2;
	}
	else if (operation == '/') {
		return op1 / op2;
	}
	return -1;
}

bool IsOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

bool IsNumber(char c) {
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}