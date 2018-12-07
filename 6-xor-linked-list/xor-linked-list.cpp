#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h> 
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *xr;
} Node;

Node *head, *tail;

Node* XOR(Node *a, Node *b)
{
    return (Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

Node* insert(int data)
{
    cout << data << endl;
    if (tail == NULL) {
        tail = new Node;
        tail->data = data;
        tail->xr = NULL;
    } else {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->xr = XOR(tail, NULL);
        tail->xr = XOR(new_node, tail->xr);
        tail = new_node;
    }

    if (head == NULL) {
        head = tail;
    }
}

void list()
{
    Node *curr = head;
    Node *prev = NULL, *next;

    while (NULL != curr) {
        cout << curr->data << " ";
        next = XOR(prev, curr->xr);
        prev = curr;
        curr = next;
    }

    cout << endl;
}

Node *get(int index)
{
    Node *curr = head;
    Node *prev = NULL, *next;

    while (NULL != curr && index > 0) {
        next = XOR(prev, curr->xr);
        prev = curr;
        curr = next;
        index--;
    }

    return curr;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40); 

    list();
    list();

    cout << get(0)->data << endl;
  
    return 0; 
}