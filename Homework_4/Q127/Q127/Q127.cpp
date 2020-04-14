#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

struct node{	
	int value;
	node *next;
	node *prev;
};

node *addBegin(node *head, int num) {
	node *temp = new node;
	temp->value = num;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;
	return temp;
}

node *addEnd(node *tail, int num) {
	node *temp = new node;
	temp->value = num;
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	return temp;
}

void add(node *head, int num, int rank) {
	node *cursor = new node;
	node *temp = new node;
	cursor = head;
	for (int i = 0; i < rank - 1; i++) {
		cursor = cursor->next;
	}
	temp->value = num;
	temp->next = cursor->next;
	temp->prev = cursor;
	cursor->next->prev = temp;
	cursor->next = temp;
}

void search(node *head, int num) {
	int result = 0;
	node *cursor = head;
	while (cursor->value != num) {
		cursor = cursor->next;
		result++;
	}
	std::cout << result << std::endl;
}

node *del(node *head, int rank) {
	node *cursor = head;
	for (int i = 0; i < rank; i++) {
		cursor = cursor->next;
	}
	if (cursor->prev != NULL) {
		cursor->prev->next = cursor->next;
	}
	if (cursor->next != NULL) {
		cursor->next->prev = cursor->prev;
	}
	if (rank == 0) {
		return cursor;
	}
	else {
		return head;
	}
}

void count(node *head) {
	int result = 0;
	node *cursor = head;
	while (cursor != NULL) {
		result++;
		cursor = cursor->next;
	}
	std::cout << result << std::endl;
}

node *reverse(node *tail) {
	node *cursor = tail;
	while (cursor->prev != NULL) {
		cursor = cursor->prev;
		node *temp = cursor->next->next;
		cursor->next->next = cursor->next->prev;
		cursor->next->prev = temp;
	}
	cursor->prev = cursor->next;
	cursor->next = NULL;
	return tail;
}

void print(node* head) {
	node *cursor = head;
	while (cursor != NULL) {
		if (cursor->next == NULL) {
			std::cout << cursor->value << std::endl;
		}
		else {
			std::cout << cursor->value << " ";
		}
		cursor = cursor->next;
	}
}

int main() {
	node *head = NULL;
	node *tail = NULL;
	node *cursor = NULL;
	
	int a;
	char c;
	while (true) {
		scanf("%d", &a);
		scanf("%c", &c);
		node *temp = new node;
		temp->value = a;
		if (head == NULL) {
			head = temp;
			head->prev = NULL;
			cursor = head;
		}
		else {
			cursor->next = temp;
			cursor->next->prev = cursor;
			cursor = cursor->next;
		}
		if (c == '\n') {
			tail = temp;
			tail->next = NULL;
			break;
		}
	}

	while (std::cin >> c) {
		char d[10];
		std::cin >> d;
		switch (c)
		{
		case 'a':
			switch (d[2]) 
			{
			case 'b':
				std::cin >> a;
				head = addBegin(head, a);
				print(head);
				break;
			case 'e':
				std::cin >> a;
				tail = addEnd(tail, a);
				print(head);
				break;
			case 'm':
				int b;
				std::cin >> a >> b;
				add(head, a, b);
				print(head);
				break;
			default:
				break;
			}
			break;
		case 's':
			std::cin >> a;
			search(head, a);
			break;
		case 'd':
			std::cin >> a;
			del(head, a);
			print(head);
			break;
		case 'c':
			count(head);
			break;
		case 'r':
			head = reverse(tail);
			print(head);
			break;
		default:
			break;
		}
	}
}