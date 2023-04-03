#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename t>
struct node{
	t data;
	node *next;
	node *prev 
	node(){
		data=0;
		next=prev=nullptr;
	}
	node(t val){
		data=val;
		next=prev=nullptr;
	}
	node(t val,node* forward){
		data=val;
		next=forward;
		prev=nullptr;
	}
	node(t val,node* forward,node* backward){
		data=val;
		next=forward;
		prev=backward;
	}
};
template<typename t>
class DoublyLinkList{
private:
	node<t>* head;
	node<t>* tail;
	//it is always advised to make head and tail both
	//int size;//not required but can be added as per ease
public:
	DoublyLinkList(){
		head=tail=nullptr;
	}
	bool isEmpty(){
		return head==tail==nullptr;
	}
	int size(){
		int n=0;
		node<t> *temp=head;
		while(temp){
			temp=temp->next;
			n++;
		}
		return n;
	}
	void InsertAtHead(t val){
		node<t> *temp=new node<t>(val);
		if(this->isEmpty())
			head=tail=temp;
		else{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
	}
	void InsertAtTail(t val){
		node<t> *temp=new node<t>(val);
		if(this->isEmpty())
			head=tail=temp;
		else{
			temp->prev=tail;
			tail->next=temp;
			tail=temp;
		}
	}
	bool Exists(t val){
		if(this->isEmpty())
			return false;
		else{
			node<t> *temp=head;
			while(temp){
				if(temp->data==val)
					return true;
				temp=temp->next;
			}
		}
		return false;
	}
	void Delete(t val){
		node<t> *temp=head;
		while(temp){
			while(temp->data==val){
				node<t> *cur=temp;
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete cur;
			}
			temp=temp->next;
		}
	}
	void Display(){
		node<t> * temp=head;
		while(temp){
			cout<<"<->"<<temp->data;
			temp=temp->next;
		}
	}
};
