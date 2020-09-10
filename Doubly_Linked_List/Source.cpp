//doubly linked list implementation
#include <iostream>
struct Node {
	int data;
	Node* prev;
	Node* next;
};

void Print(Node* head) {
	std::cout << "Forward: ";
	while (head != NULL) {
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;

};
void ReversePrint(Node* head) {
	while (head != NULL && head->next != NULL) {
		head = head->next;
	}
	std::cout << "Backward: ";
	while (head != NULL) {
		std::cout << head->data << " ";
		head = head->prev;
	}
	std::cout << std::endl;
}
void PrintAll(Node* head) {
	Print(head);
	ReversePrint(head);
}

Node* GetNewNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
Node* InsertAtTail(Node* head, Node* newNode) {
	Node* tailNode = head;
	while (tailNode->next != NULL) {
		tailNode = tailNode->next;
	}
	newNode->next = tailNode->next;
	newNode->prev = tailNode;
	tailNode->next = newNode;
	return head;
}
//pos = -1 Insert at tail
//pos = 0 Insert at head
Node* Insert(Node* head, int data, int pos) {
	Node* newNode = GetNewNode(data);
	if (pos == 0) {
		newNode->next = head;
		if (head != NULL)
			head->prev = newNode;
		head = newNode;
	}
	else if (pos == -1) {
		head = InsertAtTail(head, newNode);
	}
	else {
		//Insert at valid position
		Node* nodeBeforeInsertedNode = head;
		for (int i = 0; i < pos - 1; i++) {
			nodeBeforeInsertedNode = nodeBeforeInsertedNode->next;
		}
		newNode->next = nodeBeforeInsertedNode->next;
		nodeBeforeInsertedNode->next->prev = newNode;
		nodeBeforeInsertedNode->next = newNode;
		newNode->prev = nodeBeforeInsertedNode;
	}
	return head;
}



Node* Delete(Node* head, int pos) {
	Node* deletedNode = head;
	if (head == NULL) {
		return NULL;
	}
	if (pos == 0) {
		head = deletedNode->next;
		if(head != NULL)
		head->prev = NULL;
		delete deletedNode;
	}
	else if (pos == -1) {
		while (deletedNode->next != NULL) {
			deletedNode = deletedNode->next;
			
		}
		deletedNode->prev->next = NULL;
		delete deletedNode;
	}
	else {
		int i = 0;
		while (i < pos) {
			deletedNode = deletedNode->next;
			i++;
		}
		deletedNode->next->prev = deletedNode->prev;
		deletedNode->prev->next = deletedNode->next;
		delete deletedNode;
	}
	return head;
}

int main() {
	Node* head = NULL;
	head = Insert(head, 1, 0);
	head = Insert(head, 2, -1);
	head = Insert(head, 5, -1);
	head = Insert(head, 9, 2); // 1 2 9 5
	head = Insert(head, 7, 0); // 7 1 2 9 5
	head = Delete(head, 0);
	head = Delete(head, 0);
	head = Delete(head, 0);
	head = Delete(head, 0);
	head = Delete(head, 0);
	head = Delete(head, 0);
	PrintAll(head);
}