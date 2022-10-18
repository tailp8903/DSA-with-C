#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* createNode(int x){
	// create new node with value x;
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

Node* getList(Node* head, Node* tail, int x){
	// create Double Linked List
	Node* p = createNode(x);
	if (head == NULL){
		head = p;
		tail = p;
	}
	Node* cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = p;
	p->prev = cur;
	p->next = NULL;
	tail = p;
	return head;
}

void printListForward(Node* head){
	// print list from head to tail
	for (Node* cur = head; cur != NULL; cur = cur->next){
		printf("%d ", cur->data);
	}
}

void printListBackward(Node* tail){
	// print list from tail to head
	for (Node* cur = tail; cur != NULL; cur = cur->prev){
		printf("%d ", cur->data);
	}
}

Node* insertNodeAfter(Node* head, Node* tail, Node* p, int x){
	// insert new node after pointer p
	Node* newNode = createNode(x);
	if (head == NULL) return newNode;
	if (p == tail){
		p->next = newNode;
		newNode->prev = p;
		newNode->next = NULL;
		tail = newNode;
		return head;
	}
	p->next->prev = newNode;
	newNode->next = p->next;
	p->next = newNode;
	newNode->prev = p;
	return head;
}

Node* deleteNode(Node* p, Node* head, Node* tail){
	// delete node in list
	if (head == NULL) return NULL;
	else{
		if (p == head){
			head = head->next;
		}
		else p->prev->next = p->next;
		if (p->next != NULL){
			p->next->prev = p->prev;
		}else tail = p->prev;
		free(p);
		return head;
	}
}

Node* deleteList(Node* head){
	// delete all node in list
	Node* p = head;
	while (head != NULL){
		head = head->next;
		free(p);
		p = head;
	}
	return head;
}

int main(){
	return 0;
}