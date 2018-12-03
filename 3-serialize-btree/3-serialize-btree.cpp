#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

Node* makeNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

bool equalTree(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 != NULL && root2 != NULL) {
        return root1->key == root2->key && 
            equalTree(root1->left, root2->left) && 
            equalTree(root1->right, root2->right);
    }
    return false;
}

void serialize(Node *root, string &acc)
{
    if (root == NULL) {
        acc.append("-1 ");
        return;
    }
    acc.append(to_string(root->key));
    acc.append(" ");
    serialize(root->left, acc);
    serialize(root->right, acc);
}

void deserialize(Node *&root, vector<int> &acc)
{
    if (acc[0] == -1) {
    	acc.erase(acc.begin());
    	return;
    }
    int val = acc[0];
    acc.erase(acc.begin());
    root = makeNode(val);
    deserialize(root->left, acc);
    deserialize(root->right, acc);
}

int main() 
{
    struct Node *root = makeNode(20);
	root->left = makeNode(11);
	root->right = makeNode(23);
	root->left->left = makeNode(8);
	root->left->right = makeNode(15);
	root->right->right = makeNode(28);
	root->right->right->right = makeNode(31);
	root->right->right->right->left = makeNode(29);
	root->right->right->right->right = makeNode(35);

    string s = "";
    serialize(root, s);
    cout << s << endl;

    istringstream iss(s);
    vector<int> tokens;
    copy(istream_iterator<int>(iss),
         istream_iterator<int>(),
         back_inserter(tokens));

    Node *node = NULL;
    deserialize(node, tokens);

    string s2 = "";
    serialize(node, s2);
    cout << s2 << endl;
    
    cout << equalTree(root, node) << endl;
}