#include <stdio.h>
#include <stdlib.h>
#include "slist.h"



//dynamically allocates a new node to be inserted into the list
Node* createNode(int val){
	Node* n = malloc(sizeof(Node));
	if(n == NULL) { //if malloc fails, exit(1)
		perror("error allocating linked list.\n");
		exit(1);
	}
	n->val = val;
	n->next = NULL;
	return n;//return the node
}

//insert a new node to the front of the list.
void push(Node** head, Node* n) {
	n->next = *head;
	*head = n;

	printf("Pushed %d!\n", n->val);
	
	return;
}

//insert a node to the end of a list
void append(Node** head, Node* n) {

	if(*head == NULL){
		*head = n;
		printf("Tried appending to an empty list!\nCreated new head with val %d!!\n", n->val);
		return;
	}

	//create a temporary node to traverse the list from the head.
	Node* last = *head;

	//while loop to search for the tail node of the list
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = n;
	printf("Appended %d!\n", n->val);

	return;
}

//inserts a node after the specified node
void insert(Node* prevNode, Node* n) {
	if(prevNode == NULL) {
		perror("Cannot insert after NULL node");
		exit(1);
	}

	n->next = prevNode->next;
	prevNode->next = n;

	return;
}

//finds the first node that matches the key
Node* find(Node* head, int key) {
	Node* target = head;
	//iterate until key is found, return first node found.
	while(target != NULL) {
		if(target->val == key) {
			return target;
		}
		target = target->next;
	}
	return NULL; //target not found
}

//prints the nodes in the list in order
void printList(Node* head) {

	if(head == NULL) {
		perror("Tried printing an empty list!");
		exit(1);
	}

	Node* n = head;

	while(n != NULL){
		printf("%d -> ", n->val);
		n = n->next;
	}
	printf("NULL\n");
	
	return;
}

//destroys the list and frees the allocated memory
Node* destroy(Node* head) {
	if(head == NULL){
		return NULL;
	}
	destroy(head->next); 
	free(head);

	printf("Node deleted!\n");
	
	return NULL;
}

//deletes the first node that matches the specified key value
void delete(Node** head, int key) {

	if((*head) == NULL) {
		printf("Tried deleting in an empty list!\n");
		exit(1);
	}

	//if the head val is the target node, then delete it
	if((*head)->val == key) {
		Node* b = *head;
		*head = (*head)->next;
		free(b);
		return;
	}
	// create a temporary node to traverse and edit
	Node* curr = (*head);
	
	while(curr != NULL) {
		if(curr->next->val == key) {
			Node* b = curr->next;
			curr->next = (curr->next)->next;
			free(b);
			return;
		}
		curr = curr->next;
	}
	return;
}
