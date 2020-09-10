#pragma once
#include <string>
#include <stack>
#include <iostream>

int EvaluatePostFix(std::string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char c);
bool IsNumber(char c);

std::string InfixToPostFix(std::string infix);
bool DoesTopStackOpHaveHigherPrecedence(char topStack, char current);