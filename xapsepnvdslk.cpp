#include<iostream>
#include<string.h>
using namespace std;

struct Node{
	char data[];
	Node *next;
	Node *prev;
};
struct ItemsPosition{
	int index=0;
	Node *head;
	Node *tail;
	ItemsPosition();
	Node *createNode(char fullName[]);
	void addNewStaff(char Name[], char fullName[]);
	void searchStaffByName(int Name);
	void searchStaffByPos(int pos);
	void removeStaffByPos(int pos);
	void removeStaffByName(char Name[]);
	void getName(char name[], char fullName[]);
	void print();
};
ItemsPosition::ItemsPosition(){
	head=tail=NULL;
	head->prev=NULL;
	tail->next=NULL;
}
Node* ItemsPosition::createNode(char fullName[]){
	Node *p= new Node;
	p->data[50]=fullName[50];
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void ItemsPosition::addNewStaff(char Name[], char fullName[]){
	Node *p=new Node;
	p=createNode(fullName);
	tail->next=p;
	p->prev=tail;
	index++;
	if(index>=2){
		for(int i=0;i<index;i++){
			if(strcmp(p->data,p->prev->data)>0){
				if(i=index-1){
					p->next->prev=p->prev;
					p->prev->next=p->next;
					p->next=p->prev;
					head=p;
				}else if(i=0){
					p->prev=p->prev->prev;
					p->prev->next=p;
					tail->prev=p;
					tail->next=NULL;
				}else{
					p->next->prev=p->prev;
					p->prev->next=p->next;
					p->next=p->prev;
					p->prev=p->prev->prev;
					p->prev->next=p;
					p->next->prev=p;
				};
			}else if(i=0){
				tail=p;
				break;
			}else{
				break;
			};
		}
	}
}
void ItemsPosition::getName(char name[], char fullName[]){
	for(int i=strlen(fullName)-1;i>=0;i--){
		if(fullName[i]==' '){
			strcpy(name,fullName+1+i);
			break;
		}
	}
}
void ItemsPosition::searchStaffByPos(int pos){
	if(pos>index){
	cout<<"khong co nhan vien nao o vi tri ban can tim!";
	}else{
		Node*p=new Node;
		p=head;
		for(int i=0;i<=index;i++){
		if(i==pos){
			cout<<p;
		}else {
			p=p->next;
		}
	}
	}
}
void ItemsPosition::removeStaffByPos(int pos){
//	Node*p=searchStaffByPos(pos);
	if(pos>index){
	cout<<"khong co nhan vien nao o vi tri ban can xoa!";
	}else{
		Node*p=new Node;
		p=head;
		for(int i=0;i<=index;i++){
		if(i==pos){
			p->prev->next = p->next;
    		p->next->prev = p->prev;
    		p->prev = NULL; 
    		p->next = NULL;
    		delete p;
		}else {
			p=p->next;
		}
	}
	}
//	  p->prev->next = p->next;
//    p->next->prev = p->prev;
//    p->prev = NULL; 
//    p->next = NULL;
//    delete p;
	
}
int main(){

}
