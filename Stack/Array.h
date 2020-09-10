#pragma once
#include <iostream>
#define MAX_SIZE 101

class Array {
private:
	int Arr[MAX_SIZE];
	int top = -1;
public:
	Array() {
		top = -1;
	}

	void Push(int x) {
		if (top < MAX_SIZE-1) {
			Arr[++top] = x;
		}
	}

	void Pop() {
		if (IsEmpty()) {
			std::cout << "The stack is empty" << std::endl;
		}
		else {
			top--;
		}
	}

	int Top() {
		return Arr[top];
	}

	int IsEmpty() {
		if (top == -1) return 1;
		return 0;
	}

	void Print() {
		std::cout << "Stack: ";
		for (int i = 0; i <= top; i++) {
			std::cout << Arr[i] << " ";
		}
		std::cout << std::endl;
	}
};