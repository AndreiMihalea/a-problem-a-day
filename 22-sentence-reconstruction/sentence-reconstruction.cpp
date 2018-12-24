#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define ALPHABET_SIZE 26

typedef struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	bool isLeaf;
} TrieNode;

TrieNode* initNode()
{
	TrieNode *node = new TrieNode;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		node->children[i] = NULL;
	}
	node->isLeaf = false;
	return node;
}

void insertNode(TrieNode *root, string data)
{
	TrieNode *current = root;
	for (int i = 0; i < data.length(); i++) {
		int index = data[i] - 'a';
		if (current->children[index] == NULL) {
			current->children[index] = initNode();
		}
		current = current->children[index];
	}
	current->isLeaf = true;
}

TrieNode* search(TrieNode *root, string data)
{
	TrieNode *current = root;
	for (int i = 0; i < data.length(); i++) {
		int index = data[i] - 'a';
		if (current->children[index] == NULL) {
			return NULL;
		}
		current = current->children[index];
	}
	if (current->isLeaf) {
		return current;
	}
	return NULL;
}

void getSentence(TrieNode *root, string data, vector<string> result)
{
	int size = data.length();
	if (size == 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i <= size; i++) {
		string current = data.substr(0, i);
		if (search(root, current)) {
			vector<string> new_result;
			copy(result.begin(), result.end(), back_inserter(new_result));
            new_result.push_back(current);
			getSentence(root, data.substr(i, size - i), new_result);

		}
	}
}

int main()
{
	string dictionary[] = {"quick", "brown", "the", "fox"};

	TrieNode *root = new TrieNode;
	for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
		insertNode(root, dictionary[i]);
	}

	vector<string> result;
	getSentence(root, "thequickbrownfox", result);
}