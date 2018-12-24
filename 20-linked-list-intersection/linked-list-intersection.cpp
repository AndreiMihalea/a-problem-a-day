#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	Node *next;
} Node;

Node *initNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

void addNodeEnd(Node **head, Node *node)
{	
	if (*head == NULL) {
		*head = node;
		return;
	}

	Node *last = *head;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = node;
}

void printList(Node *head)
{
	Node *current = head;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int getCount(Node *head)
{
	int count = 0;
	Node *current = head;

	while (current != NULL) {
		count += 1;
		current = current->next;
	}

	return count;
}

Node *findIntersectionAux(int d, Node *head1, Node *head2)
{
	Node *current1 = head1, *current2 = head2;

	for (int i = 0; i < d; i++) {
		current1 = current1->next;
	}

	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2) {
			return current1;
		}
		current1 = current1->next;
		current2 = current2->next;
	}

	return NULL;
}

Node *findIntersection(Node *head1, Node *head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);

	Node *res;

	if (c1 > c2) {
		int dif = c1 - c2;
		res = findIntersectionAux(dif, head1, head2);
	} else {
		int dif = c2 - c1;
		res = findIntersectionAux(dif, head2, head1);
	}

	return res;
}

int main()
{
	Node *common = initNode(8);
	addNodeEnd(&common, initNode(10));

	Node *head1 = NULL;
	addNodeEnd(&head1, initNode(3));
	addNodeEnd(&head1, initNode(7));
	addNodeEnd(&head1, common);

	Node *head2 = NULL;
	addNodeEnd(&head2, initNode(99));
	addNodeEnd(&head2, initNode(1));
	addNodeEnd(&head2, common);

	printList(head1);
	printList(head2);

	Node *res = findIntersection(head1, head2);
	if (res) {
		cout << res->data << endl;
	} else {
		cout << "No intersection found\n";
	}
}