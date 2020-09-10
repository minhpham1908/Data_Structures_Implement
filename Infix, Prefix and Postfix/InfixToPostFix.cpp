#include "Header.h"
using std::stack;
using std::string;



std::string InfixToPostFix(std::string infix) {
	stack<char> stack;
	string postFix;
	for (string::size_type i = 0; i < infix.length(); i++) {
		if (IsNumber(infix[i])) {
			string number;
			while (i < infix.length() && IsNumber(infix[i])) {
				number += infix[i];
				i++;
			}
			i--;
			postFix.append(number);
			postFix.append(" ");
		}
		else if (IsOperator(infix[i])) {
			while (!stack.empty() && DoesTopStackOpHaveHigherPrecedence(stack.top(), infix[i])) {
				postFix += stack.top();
				postFix.append(" ");
				stack.pop();
			}
			stack.push(infix[i]); 
		}
	}
	while (!stack.empty()) {
		postFix += stack.top();
		postFix.append(" ");
		stack.pop();
	}
	return  postFix;
}

int getOpWeight(char op) {
	int weight = 0;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;
}

bool DoesTopStackOpHaveHigherPrecedence(char topStack, char current) {
	int topWeight = getOpWeight(topStack);
	int currentWeight = getOpWeight(current);

	if (topWeight == currentWeight) {
		//left-associative
		return true;
	}

	return (topWeight > currentWeight) ? true : false;
}

int main() {
	string infix("20*10+500-10");
	string postfix = InfixToPostFix(infix);
	std::cout << postfix<<"end"<<std::endl;
	int result = EvaluatePostFix(postfix);
	std::cout << "Result: " << result << std::endl;
}