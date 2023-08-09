#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main(void) {
	int x = 1;
	int y = 0;
	Node* head = NULL;
	
	while(x != 0) {
		printf("----------------------------------------------------------------------------\n1 - Push || 2 - Append || 3 - insert || 4 - print list || 5 - delete || 6 - destroy ||  0 - exit\n----------------------------------------------------------------------------\n");
		scanf("%d",&x);

		if(x == 0){
			destroy(head);
		}
	
		if(x == 1) {
			printf("What value would you like to push?\n");
			scanf("%d", &y);
			Node* n = createNode(y);
			
			push(&head, n);
		}
	
		else if(x == 2) {
			printf("What value would you like to append?\n");
			scanf("%d", &y);
			Node* n = createNode(y);
			
			append(&head, n);
		}
		
		else if(x == 3) {
			printf("Which value would you like to insert?\n");
			scanf("%d", &y);
			Node* n = createNode(y);

			printf("Which node would you like to insert after?\n");
			printList(head);
			scanf("%d", &y);

			Node *prevNode = find(head, y);

			insert(prevNode, n);
		} 
		
		else if(x == 4) {
			printList(head);
		}

		else if(x == 5) {
			printf("Which node would you like to delete?\n");
			printList(head);
			scanf("%d", &y);

			delete(&head, y);
		}
		else if(x == 6) {
			head = destroy(head);
		}
	}
}
