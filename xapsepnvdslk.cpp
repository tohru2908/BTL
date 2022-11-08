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
	void removeStaffByPos(int pos);
	void removeStaffByName(char Name[]);
	void getName(char name[], char fullName[]);
	void print();
};
ItemsPosition::ItemsPosition(){
	head=tail=NULL;
}
Node* ItemsPosition::createNode(char fullName[]){
	Node *p= new Node;
	p->data[50]=fullName[50];
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void ItemsPosition::addNewStaff(char Name[], char fullName[]){
	Node *p= new Node;
	index++;
	for(int i=0;i<index;i++){
		for(int j=i+1;j<index;j++){
			if(strcmp(p,p->next)>0&&p->next!=NULL){
				p->next=p->pre;
				p=p->next->next;
			}
			else{
				p=p->next;
			}
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

void ItemsPosition::softList(char name[], char fullName[]){
	
}
int main(){
	ItemsPosition a;
	char fullName[]="";
	char name[]= "";
	cout<<"nhap ho ten nhan vien: ";
	cin>>fullName;
	a.addNewStaff(name, fullName);
	
}
