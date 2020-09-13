#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

class BinaryTree {
private:
	Node* root = NULL;
	Node* GetNewNode(int data) {
		Node* newNode = new Node();
		newNode->left = newNode->right = NULL;
		newNode->data = data;
		return newNode;
	}
public:
	void Insert(int data) {
		if (root == NULL) {
			root = GetNewNode(data);
			return;
		}
		Node* current = root;
		Node* temp = GetNewNode(data);
		while (true) {
			if (data <= current->data) {
				if (current->left != NULL)
					current = current->left;
				else {
					current->left = temp;
					break;
				}
			}
			else if (data > current->data) {
				if (current->right != NULL)
					current = current->right;
				else {
					current->right = temp;
					break;
				}
			}
		}
	};
	int Search(int data) {
		Node* current = root;
		while (true) {
			if (current == NULL) {
				return 0;
			}
			else if (current->data == data) {
				return 1;
			}
			else if (data < current ->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	};
};