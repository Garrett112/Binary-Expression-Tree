#pragma once

#include <stack>
#include <cstring>
#include <cctype>

#include "binaryTreeType.h"

class binaryExpressionTree : public binaryTreeType {
public:
	
	void buildExpressionTree(string s) {
		stack<Node*> stack;
		char* ex = new char[s.length() + 1];
		strcpy(ex, s.c_str());
		for (int i = 0; i < s.length(); ++i) 
			if (isdigit(ex[i])) {
				Node* newNode = new Node;
				newNode->data = ex[i];
				newNode->left = nullptr;
				newNode->right = nullptr;
				stack.push(newNode);
			}
			else if (ex[i] == "+" || token == "-" || token == "*" || token == "/") {
				Node* newNode = new Node;
				newNode->data = token;
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
			else {
				cout << "Error - Unsupported Token" << endl;
				return;
			}
			token = strtok(nullptr, " ");
		}
		if (!stack.empty()) {
			root = stack.top();
			stack.pop();
			if (!stack.empty()) {
				cout << "Error, Resetting Tree" << endl;
				root = nullptr;
			}
		}
		delete ex;
	}

	double evaluateExpressionTree() {
		return calculate(root);
	}

private:
	
	double calculate(Node* n) {
		double tempL = 0;
		double tempR = 0;
		double answer = 0;
		if (n->left->data == "+" || n->left->data == "-" || n->left->data == "*" || n->left->data == "/") {
			tempL = calculate(n->left);
		}
		else {
			tempL = stod(n->left->data);
		}
		if (n->right->data == "+" || n->right->data == "-" || n->right->data == "*" || n->right->data == "/") {
			tempL = calculate(n->left);
		}
		else {
			tempR = stod(n->left->data);
		}
		if (n->data == "+") {
			answer = tempL + tempR;
		}
		else if (n->data == "-") {
			answer = tempL - tempR;
		}
		else if (n->data == "*") {
			answer = tempL * tempR;
		}
		else if (n->data == "/") {
			answer = tempL / tempR;
		}
		return answer;
	}
};

