#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* CreateNode(int data){
	// create new node
	Node* newNote = (Node*) malloc(sizeof(Node));
	newNote->data = data;
	newNote->next = NULL;
	return newNote;
}

Node* getList(Node* head, int x){
	// create Linked list
	Node* p = CreateNode(x);
	if (head == NULL) head = p;
	else{
		Node* cur = head;
		while(cur->next != NULL){
			cur = cur -> next;
		}
		cur->next = p;
	}	
	return head;
}

void printList(Node* head){
	// print current list
	Node* cur = head;
	while(cur != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

Node* insertToHead(Node* head, int x){
	// create new node with value x and insert to head of linked list
	Node* p = CreateNode(x);
	if (head == NULL) return p;
	else{
		p->next = head;
		head = p;
		return head;
	}
}

Node* insertAfter(Node* head, Node* cur, int x){
	// insert new node after the positon pointed by pointer cur
	Node* p = CreateNode(x);
	if (head == NULL) return p;
	p->next = cur->next;
	cur->next = p;
	return head;
}

Node* insertBefore(Node* head, Node* cur, int x){
	// insert new node before the position pointed by pointer cur
	Node* p = CreateNode(x);
	if (head == NULL) return p;
	Node* prev = head;
	while(prev->next != cur){
		prev = prev->next;
	}
	prev->next = p;
	p->next = cur;
	return head;
}

Node* inserToTail(Node* head, int x){
	// insert new node to the last of linked list
	Node* p = CreateNode(x);
	if (head == NULL) return p;
	Node* cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = p;
	return head;
}

Node* deleteFirstNode(Node* head){
	// delete the first node
	Node* first = head;
	head = head->next;
	free(first);
	return head;
}

Node* deleteNode(Node* head, Node* del){
	// delete node del
	if (del == head){
		return deleteFirstNode(del);
	}
	Node* cur = head;
	while(cur->next != del){
		cur = cur->next;
	}
	cur->next = del->next;
	free(del);
	return head;
}

Node* deleteAllNode(Node* head){
	// delete all node
	Node* del = head;
	while(del != NULL){
		head = head->next;
		free(del);
		del = head;
	}
	return head;
}

int searchNode(Node* head, int x){
	// search node have data x 
	Node* cur = head;
	while(cur != NULL){
		if (cur->data == x) return 1;
		cur = cur->next;
	}
	return 0;
}

Node* sortLinkedList(Node* head){
	// sort the list in ascending order
	for (Node* i = head; i->next != NULL; i = i->next){
		for (Node* j = i->next; j != NULL; j = j->next){
			if (i->data > j->data){
				int temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	return head;
}

Node* reverseList(Node* head){
	Node* lst = (Node*) malloc(sizeof(Node));
	lst = NULL;
	for (Node* cur = head; cur != NULL; cur = cur->next){
		lst = insertToHead(lst, cur->data);
	}
	return lst;
}

int main(){
	Node* head = NULL;
	int n;
	printf("Enter number of notes: ");
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		int x;
		printf("Enter value of node %dth: ", i);
		scanf("%d", &x);
		head = getList(head, x);
	}
	printList(head);
	head = sortLinkedList(head);
	printList(head);
	// printf("%d", searchNode(head, 3));
	Node* reversedList = reverseList(head);
	printList(reversedList);
	return 0;
}