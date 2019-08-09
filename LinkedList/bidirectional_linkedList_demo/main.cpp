#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {

	char *data;
	Node* next;
	Node* previous;
};

char strhead[] = { "_H_E_A_D_" };


Node *createLinkedList();
void show(Node *head);
void Conversely(Node* head);
int main()
{
	Node *head=createLinkedList();
	show(head);
//	Linux doesn't have this following function
//	system("pause");
	//pause();
	cin.get();
	cin.get();
}

void Conversely(Node* head) {
	cout << "************************" << endl;
	if (head->previous->data == strhead) {
		cout << head->data << endl;
		delete head;
		return;
	}
		
	head = head->previous;

	while (head->previous!=NULL&&head->previous->data!= strhead) {
		head = head->previous;
		cout << head->next->data << endl;
		delete head->next;
		
	}
		cout << head->data << endl;
		delete head;

}
Node* createLinkedList() {
	Node* head, * p1;
	head = new Node;

	p1 = head;

	head->data = strhead;
	char *temp=new char[30];

	cout << "Please enter data:\n";
	cin >> temp;
	while (temp[0] != '0') {

		p1->next = new Node;
		p1->next->data= temp;
		p1->next->previous = p1;
		p1 = p1->next;

		temp = new char[30];
		cout << "Please enter data:\n";
		cin >> temp;
	}

	p1->next = NULL;
	head->previous = p1;
	return head;
}

void show(Node *head) {
	cout << "************************" << endl;
	while (head->next != NULL) {
		head = head->next;

		cout << head->previous->data<< endl;
		delete head->previous;
	}

	cout << head->data << endl;
	delete head;
}
