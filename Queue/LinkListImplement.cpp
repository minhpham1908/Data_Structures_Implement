#include "Header.h"
#include <iostream>
bool SinglyLinkedListQueue::Empty() {
	if (front == NULL && rear == NULL) {
		std::cout << "Queue is empty"<<std::endl; return true;
	}
	return false;
}
void SinglyLinkedListQueue::EnQueue(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (Empty()) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}
void SinglyLinkedListQueue::Dequeue() {
	if (Empty()) return;
	Node* temp = front;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	delete temp;
}
int SinglyLinkedListQueue::Front() {
	return front->data;
}
void SinglyLinkedListQueue::Print() {
	Node* temp = front;
	int i = 0;
	std::cout << "Queue: ";
	Empty();
	while (temp!=NULL) {
		std::cout<< temp -> data << " ";
		i++;
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool SinglyLinkedListQueue::Full() {
	//never happen <(")
	return false;
}