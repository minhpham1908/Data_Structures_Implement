#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

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
			else if (data < current->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	};
	Node* GetRootPtr() {
		return root;
	}
	int FindTreeHeightRecursively(Node* current) {
		if (current == NULL) {
			return -1;
		}
		return std::max(FindTreeHeightRecursively(current->left), FindTreeHeightRecursively(current->right)) + 1;
	}

};

void LevelOrderTravesal(Node* root) {
	if (root == NULL) return;
	std::queue<Node*> queue;
	queue.push(root);
	while (!queue.empty()) {
		Node* current = queue.front();
		queue.pop();
		std::cout << current->data << " ";
		if (current->left) queue.push(current->left);
		if (current->right) queue.push(current->right);
	}
}

//root left right
/*all 3 below function:
//space complexity O(h), h = height of tree = O(n) if nodes have onely left or right child, or = O(log2(n)) avarage
//time complexity O((n), n = number of nodes
*/
void PreOrderTravesal(Node* root) {
	if (root == NULL) return;
	std::cout << root->data << " ";
	PreOrderTravesal(root->left);
	PreOrderTravesal(root->right);
}

//left root right
void InOrderTravesal(Node* root) {
	if (root == NULL) return;
	InOrderTravesal(root->left);
	std::cout << root->data << " ";
	InOrderTravesal(root->right);
}

//left right root
void PostOrderTravesal(Node* root) {
	if (root == NULL) return;
	PostOrderTravesal(root->left);
	PostOrderTravesal(root->right);
	std::cout << root->data << " ";
}

bool IsBinarySearchTree(Node* root, int min, int max) {
	if (root == NULL) return true;
	if (root->data > min
		&& root->data <= max
		&& IsBinarySearchTree(root->left, min, root->data)
		&& IsBinarySearchTree(root->right, root->data, max))
		return true;
	else return false;
}

bool IsBinarySearchTreeInOrder(Node* current) {
	std::stack<Node*> S;
	int value = INT_MIN;
	while (current != NULL || !S.empty()) {
		while (current != NULL) {
			S.push(current);
			current = current->left;

		}
		current = S.top();
		S.pop();
		if (current->data >= value) { value = current->data; }
		else  return false;
		current = current->right;
	}
	return true;
}

int main() {
	BinaryTree tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(2);
	tree.Insert(4);
	tree.Insert(6);
	tree.Insert(8);

	/*
		 5
	   /   \
	  3	     7
	 / \    /  \
	2   4   6   8
	*/

	std::cout << "LevelOrder Travesal: ";
	LevelOrderTravesal(tree.GetRootPtr());
	std::cout << std::endl;
	std::cout << "PreOrder Travesal: ";
	PreOrderTravesal(tree.GetRootPtr()); // 5 3 2 4 7 6 8
	std::cout << std::endl;
	std::cout << "InOrderTravesal Travesal: ";
	InOrderTravesal(tree.GetRootPtr()); // 2 3 4 5 6 7 8
	std::cout << std::endl;
	std::cout << "PostOrder Travesal: ";
	PostOrderTravesal(tree.GetRootPtr()); // 2 4 3 6 8 7 5
	std::cout << std::endl;
	std::cout << "Is Binary Search Tree: "<< IsBinarySearchTree(tree.GetRootPtr(), INT_MIN, INT_MAX) << " ";
	std :: cout << "Is Binary Search Tree :" <<IsBinarySearchTreeInOrder(tree.GetRootPtr());


}