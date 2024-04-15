#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node {
	 string data;
	 Node* left;
	 Node* right;
};

class binaryTreeType {
public:

	binaryTreeType() {
		root = nullptr;
	}

	~binaryTreeType() {
		destroy(root);
	}

	void insertNew(string d) {
		insert(d, root);
	}

	bool searchValue(string d) {
		search(d, root);
	}

protected:

	Node* root;

private:

	void insert(string d, Node* n) {
		if (n == nullptr) {
			n = new Node;
			n->data = d;
		}
		else if (d < n->data) {
			insert(d, n->left);
		}
		else {
			insert(d, n->right);
		}
	}

	bool search(string d, Node* n) {
		if (n == nullptr) {
			return 0;
		}
		else if (d == n->data) {
			return 1;
		}
		else if (d == n->data) {
			return search(d, n->left);
		}
		else {
			return search(d, n->right);
		}
	}

	void destroy(Node* n) {
		if (n != nullptr) {
			destroy(n->left);
			destroy(n->right);
			delete n;
		}
	}

};

