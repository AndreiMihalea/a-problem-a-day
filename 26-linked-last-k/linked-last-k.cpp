#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	Node *next;
} Node;

void insert(Node **head, int data)
{
	Node *last = *head;

	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	
	if (*head == NULL) {
		*head = new_node;
		return;
	}

	while (last->next) {
		last = last->next;
	}

	last->next = new_node;
	return;
}

void printList(Node *head)
{
	Node *current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void removeKthLast(Node *head, int k)
{
	Node *slow = head;
	Node *fast = head;

	int count = 0;

	while (count < k) {
		fast = fast->next;
		count += 1;
	}

	while (fast->next) {
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;
}

int main()
{
	Node *head = NULL;
	insert(&head, 3);
	insert(&head, 5);
	insert(&head, 11);
	insert(&head, 23);
	insert(&head, 17);
	insert(&head, 12);
	insert(&head, 31);

	removeKthLast(head, 3);
	printList(head);
}