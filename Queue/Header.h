#pragma once
#include <iostream>

#define N 10
class ArrayQueue {
private:
	int front = -1;
	int rear = -1;
	int A[N];

public:
	bool Empty();
	void EnQueue(int x);
	int Dequeue();
	int Front();
	void Print();
private:
	bool Full();
};
struct Node {
	int data;
	Node* next;
};
class SinglyLinkedListQueue {
private:
	Node* front = NULL, * rear =NULL;
public:
	bool Empty();
	void EnQueue(int x);
	void Dequeue();
	int Front();
	void Print();
private:
	bool Full();
};