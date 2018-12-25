#include <iostream>

using namespace std;

class LockingBTNode {
public:
	int data;
	LockingBTNode *left;
	LockingBTNode *right;
	LockingBTNode *parent;
	bool is_locked;
    int locked_descentants;
	bool isLocked();
	bool lock();
	bool unlock();
    LockingBTNode(int value);
private:
	bool canModify();
};

LockingBTNode::LockingBTNode(int value)
{
    data = value;
    left = NULL;
    right = NULL;
    parent = NULL;
    is_locked = false;
    locked_descentants = 0;
}

bool LockingBTNode::canModify()
{
	if (locked_descentants > 0) {
		return false;
	}

	LockingBTNode *current = parent;
	while (current) {
		if (current->is_locked) {
			return false;
		}
		current = current->parent;
	}
	return true;
}

bool LockingBTNode::isLocked()
{
	return is_locked;
}

bool LockingBTNode::lock()
{
	if (canModify()) {
		is_locked = true;
		LockingBTNode *current = parent;
		while (current) {
			current->locked_descentants += 1;
			current = current->parent;
		}
		return true;
	}
	return false;
}

bool LockingBTNode::unlock()
{
	if (canModify()) {
		is_locked = false;
		LockingBTNode *current = parent;
		while (current) {
			current->locked_descentants -= 1;
			current = current->parent;
		}
		return true;
	}
	return false;
}

void insertNode(LockingBTNode *node, int value)
{
    if (value < node->data) {
        if (!node->left) {
            node->left = new LockingBTNode(value);
            node->left->parent = node;
        } else {
            insertNode(node->left, value);
        }
    } else {
        if (!node->right) {
            node->right = new LockingBTNode(value);
            node->right->parent = node;
        } else {
            insertNode(node->right, value);
        }
    }
}

int main()
{
	LockingBTNode *node = new LockingBTNode(10);
    insertNode(node, 13);
    insertNode(node, 5);
    insertNode(node, 3);
    insertNode(node, 7);
    insertNode(node, 21);
    // Some tests
    cout << node->lock() << endl;
    cout << node->isLocked() << endl;
    cout << node->unlock() << endl;
    cout << node->isLocked() << endl;
    cout << node->right->lock() << endl;
    cout << node->unlock() << endl;
    cout << node->right->unlock() << endl;
    cout << node->unlock() << endl;
}