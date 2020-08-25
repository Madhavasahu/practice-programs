/*
 ============================================================================
 Name        : SingleLL.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
void display(struct Node *head);
struct Node* addNode(struct Node *head);
int main(void) {
	struct Node *head = NULL;
	
	display(display(head));
}

struct Node* addNode(struct Node *head) {
	int data;
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	printf("Enter the data");
	scanf("%d", &data);
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	} else {
		struct Node *ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
	return head;
}
void display(struct Node *head) {
	struct Node* ptr = head;
	if (head == NULL)
		printf("list is empty");
	else {
		while (ptr != NULL) {
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
	}
}
