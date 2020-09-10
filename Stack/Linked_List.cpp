#include <iostream>
struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* top = NULL;
public:
	void Push(int data) {
		Node* temp = new Node();
		temp->data = data;
		temp->next = top;
		top = temp;
	}

	void Pop() {
		if (top == NULL)
			return;
		Node* temp;
		temp = top;
		top = top->next;
		delete temp;
	}

	int Top() {
		return top->data;
	}

	int Empty() {
		if (top == NULL) {
			return 1;
		}
		else return 0;
	}
	void Print() {
		Node* temp = top;
		std::cout << "List :";
		while (temp != NULL) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	LinkedList linklist;
	linklist.Empty();
	linklist.Push(2);
	linklist.Print();
	linklist.Empty();
	linklist.Push(4);
	linklist.Print();
	linklist.Push(6);
	linklist.Print();
	linklist.Push(5);
	linklist.Print();
	linklist.Pop();
	linklist.Print();
	linklist.Pop();
	linklist.Pop();
	linklist.Print();
	linklist.Pop();
	linklist.Pop();

	linklist.Print();
}