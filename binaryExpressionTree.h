#pragma once

#include <stack>
#include <cstring>
#include <cctype>
#include <vector>

#include "binaryTreeType.h"

class binaryExpressionTree : public binaryTreeType {
public:
	
	void buildExpressionTree(string s) {
		stack<Node*> stack;
		int l = s.length();
		char* ex = new char[l+1];
		strcpy(ex, s.c_str());
		for (int i = 0; i < l; ++i) {
			if (isdigit(ex[i])) {
				string t(1, ex[i]);
				while (isdigit(ex[i + 1]) && i < l+1) {
					t.push_back(ex[i + 1]);
					i++;
				}
				Node* newNode = new Node;
				newNode->data = t;
				newNode->left = nullptr;
				newNode->right = nullptr;
				stack.push(newNode);
			}
			else if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/') {
				Node* newNode = new Node;
				newNode->data = ex[i];
				if (!stack.empty()) {
					newNode->left = stack.top();
					stack.pop();
					if (!stack.empty()) {
						newNode->right = stack.top();
						stack.pop();
						stack.push(newNode);
					}
					else {
						cout << "Error - Stack is Empty" << endl;
						return;
					}
				}
				else {
					cout << "Error - Stack is Empty" << endl;
					return;
				}

			}
			else if (ex[i] == ' ') {

			}
			else {
				cout << "Error - Unsupported Token" << endl;
				return;
			}
		}
		if (!stack.empty()) {
			root = stack.top();
			stack.pop();
			if (!stack.empty()) {
				cout << "Error, Resetting Tree" << endl;
				root = nullptr;
			}
		}
		delete[] ex;
	}

	double evaluateExpressionTree() {
		return calculate(root);
	}

private:
	
	double calculate(Node* n) {
		if (n->left->data == "+" || n->left->data == "-" || n->left->data == "*" || n->left->data == "/") {
			if (n->right->data == "+" || n->right->data == "-" || n->right->data == "*" || n->right->data == "/") {
				return operate(n->data, calculate(n->left), calculate(n->right));
			}
			else {
				return operate(n->data, calculate(n->left), stod(n->right->data));
			}
		}
		else {
			if (n->right->data == "+" || n->right->data == "-" || n->right->data == "*" || n->right->data == "/") {
				return operate(n->data, stod(n->left->data), calculate(n->right));
			}
			else {
				return operate(n->data, stod(n->left->data), stod(n->right->data));
			}
		}
	}

	double operate(string o, double l, double r) {
		if (o == "+") {
			return r + l;
		}
		else if (o == "-") {
			return r - l;
		}
		else if (o == "*") {
			return r * l;
		}
		else if (o == "/") {
			return r / l;
		}
	}
};

