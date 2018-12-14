#include <iostream>
#include <string>
using namespace std;

const int SIZE = 26;

typedef struct Trie {
	Trie *children[SIZE];
	bool leaf;
} Trie;

Trie* getNode()
{
	Trie *node = new Trie;
	node->leaf = false;
	for (int i = 0; i < SIZE; i++)
		node->children[i] = NULL;
	return node;
}

void insertNode(Trie *root, string data)
{
	Trie *current = root;
	for (int i = 0; i < data.length(); i++) {
		int id = data[i] - 'a';
		if (current->children[id] == NULL) {
			current->children[id] = getNode();
		}
		current = current->children[id];
	}
	current->leaf = true;
}

Trie* search(Trie *root, string data)
{
	Trie *current = root;
	for (int i = 0; i < data.length(); i++) {
		int id = data[i] - 'a';
		if (!current->children[id]) {
			return NULL;
		}
		current = current->children[id];
	}
	return current;
}

void completeHelper(Trie *root, string current)
{
	if (root->leaf) {
		cout << current << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		if (root->children[i]) {
			string copy = current;
			copy.push_back('a' + i);
			completeHelper(root->children[i], copy);
		}
	}
}

void complete(Trie *root, string data)
{
	Trie *node = search(root, data);
	if (!node) {
		cout << "No results\n";
		return;
	}
	completeHelper(node, data); 
}

int main()
{
	Trie *root = getNode();
	insertNode(root, "dog");
	insertNode(root, "deer");
	insertNode(root, "deal");
	complete(root, "z");
	return 0;
}