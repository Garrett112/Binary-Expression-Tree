#pragma once

#include "binaryTreeType.h"

class binaryExpressionTree : public binaryTreeType {
public:
	
	void buildExpressionTree() {

	}

	double evaluateExpressionTree() {
		return calculate(root);
	}

private:
	
	double calculate(Node* n) {
		double tempL;
		double tempR;
		double answer;
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

