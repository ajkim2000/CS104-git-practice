#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

//Helper functions?
int rangeSum(Node *root, int L, int R) {
	int answer = 0;
	std::stack<Node*> temp;
	temp.push(root);
	while(!temp.empty()) {
		Node* tmp = temp.top();
		temp.pop();
		if (tmp != NULL) {
			if (tmp->key >= L && tmp->key <= R) {
				answer += tmp->key;
			}
			if (tmp->key > L) {
				temp.push(tmp->left);
			}
			if (tmp->key < R) {
				temp.push(tmp->right);
			}
		}
	}
	return answer;
}

int height(Node *root) {
	if (root == NULL) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}
//Helper functions?
bool isBalanced(Node *root) {
	bool left = false;
	bool right = false;
	int lh = 0;
	int rh = 0;
	if (root == NULL) {
		return true;
	}
	left = isBalanced(root->left);
	right = isBalanced(root->right);
	lh = height(root->left);
	rh = height(root->right);
	int answer = abs(lh - rh);
	return (answer <= 1 && left && right);
}
