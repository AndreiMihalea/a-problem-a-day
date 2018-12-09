#include <iostream>
#include <stdio.h>
#include <utility>
#include <tuple>
using namespace std;

typedef struct node {
	int data;
	node *left;
	node *right;
} node;

pair<int, int> count_unival(node *root)
{
	if (root == NULL) {
		return make_pair(0, 1);
	}

	int count_left, unival_left, count_right, unival_right;
	tie(count_left, unival_left) = count_unival(root->left);
	tie(count_right, unival_right) = count_unival(root->right);
	int total = count_left + count_right;
	if (unival_left && unival_right) {
		if (root->left != NULL and root->right != NULL) {
			if (root->left->data != root->right->data) {
				return make_pair(total, 0);
			}
		}
		return make_pair(total + 1, 1);
	}

	return make_pair(total, 0);
}

node *newNode(int data)
{
	node *n = (node*)malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main()
{
	node *root = newNode(0);
	root->left = newNode(1);
	root->right = newNode(0);
	root->right->left = newNode(1);
	root->right->right = newNode(0);
	root->right->left->left = newNode(1);
	root->right->left->right = newNode(1);
	int count, unival;
	tie(count, unival) = count_unival(root);
	cout << count << endl;
	return 0;
}