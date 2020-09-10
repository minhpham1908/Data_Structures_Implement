#include <iostream>
#include "Header.h"

bool ArrayQueue::Empty() {
	if (front == -1 && rear == -1) return true;
	return false;
}

bool ArrayQueue::Full() {
	if (((rear + 1) % N) == front) return true;
	return false;
}
void ArrayQueue::EnQueue(int x) {
	if (Full()) {
		std::cout << "Queue is full, please dequeue first." << std::endl;
		return;
	}
	else if (Empty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % N;
	}
	A[rear] = x;
}

int ArrayQueue::Front() {
	if (Empty()) {
		std::cout << "Queue is empty. Please insert more element" << std::endl;
		return -1;
	}
	else {
		return A[front];
	}
}
int ArrayQueue::Dequeue() {
	if (Empty()) {
		std::cout << "Queue is empty. Please insert more element" << std::endl;
		return -1;
	}
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		int result = Front();
		front = (front + 1) % N;
		return result;
	}
}

void ArrayQueue::Print() {
	std::cout << "Empty: " << Empty() << std::endl;
	std::cout << "Full: " << Full() << std::endl;

	if (!Empty()) {
		std::cout << "Front is at " << front << ", value: " << A[front] << std::endl;
		std::cout << "Rear: " << rear << ", value: " << A[rear] << std::endl;
	}
	std::cout << std::endl;
}