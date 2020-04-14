#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

struct Node {
	int value;
	Node *next;
};

int main() {
	int num;
	Node *cursors[10];
	Node *heads[10];
	Node *result = new Node;
	Node *reCursor = result;
	
	std::cin >> num;
	for (int i = 0; i < num; i++) {
		heads[i] = new Node;
		cursors[i] = heads[i];
		
		int a;
		char c;
		while (true) {
			scanf("%d", &a);
			scanf("%c", &c);
			Node *p = new Node;
			p->value = a;
			p->next = NULL;
			cursors[i]->next = p;
			cursors[i] = p;
			if (c == '\n') {
				cursors[i] = heads[i]->next;
				break;
			}
		}
	}

	while (true) {
		int index = -1;
		Node *temp = NULL;
		for (int i = 0; i < num; i++) {
			if (cursors[i] != NULL) {
				if (temp == NULL) {
					temp = cursors[i];
					index = i;
				}
				else {
					if (temp->value > cursors[i]->value) {
						temp = cursors[i];
						index = i;
					}
				}
			}
		}
		if (temp == NULL) {
			break;
		}
		else {
			cursors[index] = cursors[index]->next;
			reCursor->next = temp;
			reCursor = reCursor->next;
		}
	}

	reCursor = result->next;
	while (reCursor != NULL) {
		if (reCursor->next == NULL) {
			std::cout << reCursor->value << std::endl;
		}
		else {
			std::cout << reCursor->value << " ";
		}
		reCursor = reCursor->next;
	}
}