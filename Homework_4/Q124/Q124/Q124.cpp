#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

struct Node {
	int value;
	Node *next;
};

int main() {
	Node *head = new Node;
	Node *cursor = head;
	Node *mark = head;
	int key;

	int a;
	char c;
	while (true) {
		scanf("%d", &a);
		scanf("%c", &c);
		Node *p = new Node;
		p->value = a;
		p->next = NULL;
		cursor->next = p;
		cursor = p;
		if (c == '\n') {
			break;
		}
	}
	std::cin >> key;

	cursor = head;
	while (cursor->next != NULL) {
		if (cursor->next->value < key) {
			if (mark == cursor) {
				mark = mark->next;
				cursor = cursor->next;
			}
			else {
				Node *temp = cursor->next;
				cursor->next = cursor->next->next;
				temp->next = mark->next;
				mark->next = temp;
				mark = mark->next;
			}
		}
		else {
			cursor = cursor->next;
		}
	}

	cursor = head->next;
	while (cursor != NULL) {
		if (cursor->next == NULL) {
			std::cout << cursor->value << std::endl;
		}
		else {
			std::cout << cursor->value << "->";
		}
		cursor = cursor->next;
	}
}