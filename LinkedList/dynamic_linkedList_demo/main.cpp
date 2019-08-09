/*
 * modification time      2019-7-30 
 *
 * author                 zyb
 *
 * description		  This is a dynamic linked list demo,
 * 			 dynamic allocation memory and delete memory
 * */

#include<iostream>
using namespace std;

struct Student{
	char *name;
	Student *next;
};
Student *createDynamicLinkedList();
void showNode(Student *head);//show linked list
void showConversely(Student *head);
bool insertNodeAfter(Student *head,Student *insertNode,int nodePosition);
bool deleteNode(Student *head,int deletePosition);
int size(Student *head);
int main()
{
/*
	Student *head, *s1, *s2;
	head = new Student;
	s1 = s2 = head;

	cout << "Please input data (q is exit)" << endl;
	char *data = new char[40];
	cin >> data;
	while (*data != '0')
	{
		s1->name = data;
		s2 = s1;

		s1 = new Student;
		s2->next = s1;
		cout << "Please input data (q is exit)" << endl;
		data = new char[40];
		cin >> data;
	}
	s2->next = NULL;
*/
Student *head=createDynamicLinkedList();
showNode(head);
int x=0;
cout<<"plead enter you soon delete node number:"<<endl;
cin>>x;
deleteNode(head,x);
showNode(head);
//head=head++;
//Student *temp=head++;
//cout<<temp->name;
	//showNode(head);
cout<<"count :"<<size(head)<<endl;
	return 0;
}




bool deleteNode(Student *head,int deletePosition){
	int count=0;
	Student *temp=head;
	while(temp!=NULL){
		count++;	
		if(count==deletePosition){
			if(temp->next!=NULL){
				if(temp->next->next!=NULL){
					Student *dd=temp->next->next;
					delete temp->next;
					temp->next=dd;
				}else{
					
					delete temp->next;
				}
				return true;
			}
			return false;
		}
		
		temp=temp->next;
	}
	return false;

}
Student *createDynamicLinkedList(){

	cout << "Please input data (q is exit)" << endl;
	char *data = new char[40];
	cin >> data;
	if(*data=='0')
		return NULL;

	Student *head, *s1, *s2;
	head = new Student;
	head->name="head";
	s1 = s2 = head;

	while (*data != '0')
	{
		
		s1 = new Student;
		s1->name = data;
		s2->next = s1;
		s2 = s1;
		cout << "Please input data (q is exit)" << endl;
		data = new char[40];
		cin >> data;
	}
	s2->next = NULL;
	return head;
}
int size(Student *head){
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}
	return count-1;
}
bool insertNodeAfter(Student *head,Student *insertNode,int nodePosition){
	//if node is null ,return false
	if(insertNode==NULL)
		return false;
	int count=0;
	while(head->next!=NULL){
		count++;
		
		if(count==nodePosition){
			//Student *temp=head;
			Student *temp2=head->next;
			head->next=insertNode;
			insertNode->next=temp2;
			return true;
		}
		head=head->next;

	}
	head->next=insertNode;
	insertNode->next=NULL;	

return true;
}
/**
 * discription:	This is output function,order of the output is first in,
 * 		first out.Be carefu! The memory of the application is not 
 * 		release.
 * parament:
 * 	Student *head:"Student" type pointer.
 *
 */

void showNode(Student *head){
	cout<<"showNode() Function run..."<<endl;
	while (head != NULL){
		if(head->name!="head")
			cout << head->name << endl;
		head = head->next;
	}
}
/**
 * discription: This is a output and release memory function,order of the    *		   output and release is last in first out.
 * parament:
 * 	Student *head: "Student" type pointer.
 */
void showConversely(Student *head){
	if (head == NULL)
		return;
	if (head->next != NULL){
		  showConversely(head->next);
	}
		cout << "delete " << head->name << endl;
		delete head;
		head=NULL;
}

