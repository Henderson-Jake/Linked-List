#ifndef SLIST_H
#define SLIST_H

typedef struct Node
{
    int val;
    struct Node* next;
    
}Node;


Node* createNode(int);
void push(Node**, Node*);
void append(Node**, Node*);
void insert(Node*, Node*);
Node* find(Node*, int);
void printList(Node*);
Node* destroy(Node*);
void delete(Node**, int);

#endif
