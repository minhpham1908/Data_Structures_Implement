#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct Node {
	int data;
	struct Node* next;
};

Node* Insert(Node* head, int data, int pos) {
	Node* insertedNode = new Node();
	insertedNode->data = data;
	insertedNode->next = NULL;
	if (pos == 1) {
		insertedNode->next = head;
		head = insertedNode;
		return head;
	}
	Node* nodeBeforeInsertedNode = head;
	for (int i = 0; i < pos - 2; i++) {
		nodeBeforeInsertedNode = nodeBeforeInsertedNode->next;
	}
	insertedNode->next = nodeBeforeInsertedNode->next;
	nodeBeforeInsertedNode->next = insertedNode;
	return head;
};
void Print(Node* const head) {
	Node* temp = head;
	while (temp != NULL) {
		std::cout << " " << temp->data;
		temp = temp->next;
	}
	std::cout << std::endl;
};

Node* Delete(Node* head, int pos) {
	if (pos == 1) {
		Node* deletedNode = head;
		head = deletedNode->next;
		delete deletedNode;
		return head;
	}

	Node* previousNode = head;
	for (int i = 0; i < pos - 2; i++) {
		previousNode = previousNode->next;
	}
	Node* deletedNode = previousNode->next;
	previousNode->next = deletedNode->next;
	delete deletedNode;
	return head;
};

Node* Reverse(Node* head) {
	Node* prev, * current, * next;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}
void ReversePrint(Node* node) {
	if (node == NULL) {
		return;
	}
	ReversePrint(node->next);
	std::cout << " " << node->data;
}

Node* RecursionReverse(Node* head) {
	if (!(head && head->next)) {
		return head;
	}
	Node* node = RecursionReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}

int main() {
	Node* head = NULL;
	ReversePrint(head);

	head = Insert(head, 1, 1);//1
	head = Insert(head, 2, 1);//2 1
	head = Insert(head, 3, 2);//2 3 1
	head = Insert(head, 5, 2);//2 5 3 1
	head = Insert(head, 4, 4);//2 5 3 4 1
	head = RecursionReverse(head);
	Print(head);
}