#pragma once

#include <stack>
#include <cstring>
#include <cctype>
#include <vector>

#include "binaryTreeType.h"

class binaryExpressionTree : public binaryTreeType {
public:
	
	void buildExpressionTree(string s) {
		stack<Node*> stack;									//creates stack
		int l = s.length();									//sets the integer l to the length of s
		char* ex = new char[l+1];							//creates an array of character of length l
		strcpy(ex, s.c_str());								//breaks string s into an array of character (ex)
		for (int i = 0; i < l; ++i) {						//for the length of the array
			if (isdigit(ex[i])) {							//if ex[i] is an integer
				string t(1, ex[i]);							//convert the character to a string
				while (isdigit(ex[i + 1]) && i < l+1) {		//while ex[i+1] is also an integer
					t.push_back(ex[i + 1]);					//combine that character with the string (so 3 and 5 turn to 35)
					i++;									//move to the next character in ex
				}
				Node* newNode = new Node;					//create a new node
				newNode->data = t;							//set the node's data to the value of the string
				newNode->left = nullptr;					//set the left pointer to nullptr
				newNode->right = nullptr;					//set the right pointer to nullptr
				stack.push(newNode);						//push the new node onto the stack
			}
			else if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/') { //if the ex[i] is an operator
				Node* newNode = new Node;					//create a new node
				newNode->data = ex[i];						//set the node's data to the value of ex[i]
				if (!stack.empty()) {						//if the stack is not empty
					newNode->left = stack.top();			//set the left pointer to the top of the stack
					stack.pop();							//pop the stack
					if (!stack.empty()) {					//if the stack is not empty
						newNode->right = stack.top();		//set the right pointer to the top of the stack
						stack.pop();						//pop the stack
						stack.push(newNode);				//push the new node onto the stack
					}
					else {									//else
						cout << "Error - Stack is Empty" << endl;	//give error message
						return;
					}
				}
				else {										//else
					cout << "Error - Stack is Empty" << endl;		//give error message
					return;	
				}

			}
			else if (ex[i] == ' ') {						//if ex[i] is a space
															//do nothing
			}
			else {											//else
				cout << "Error - Unsupported Token" << endl;	//give error message
				return;
			}
		}
		if (!stack.empty()) {								//if the stack is not empty
			root = stack.top();								//set the root equal to the top of the stack
			stack.pop();									//pop the stack
			if (!stack.empty()) {							//if the stack is still not empty
				cout << "Error, Resetting Tree" << endl;	//give error message
				root = nullptr;								//set the root equal to nullptr
			}
		}
		delete[] ex;										//delete the character array
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

