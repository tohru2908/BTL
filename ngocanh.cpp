#include<iostream>
#include<string.h>
using namespace std;


struct vitri{
	string hoten;
};
struct Node{
	vitri data;
	Node *next;
	Node *prev;
};
struct ItemsPosition{
	int size=0;
	Node *head;
	Node *tail;
	ItemsPosition();
	Node *createNode(string fullName);
	void addNewStaff(char name[], string fullName);
	void searchStaffByName(int name);
	void searchStaffByPos(int pos);
	void removeStaffByPos(int pos);
	void removeStaffByName(char name[]);
	void getName(char name[], string fullName);
	void print();
};
ItemsPosition::ItemsPosition(){
	head=tail=NULL;
//	head->prev=NULL;
//	tail->next=NULL;
}
Node* ItemsPosition::createNode(string fullName){
	Node *p= new Node;
	p->data.hoten=fullName;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void ItemsPosition::addNewStaff(char name[], string fullName){
	cout<<"nhap ho ten ten nhan vien: ";
	getline(cin,fullName);
	char f[50],g[50];
	Node *p=new Node;
	p=createNode(fullName);
//	tao node p nam o vi tri cuoi
	if (tail!=NULL){
	tail->next=p;
	p->prev=tail;}
	else tail=p;
	size++;
	getName(f,p->data.hoten);
	Node *q=p->prev;
	getName(g,q->data.hoten);
//	danh sach co nhieu hon 1 phan tu thi bat dau cho sap xep
	if(size>=2){
		for(int i=0;i<size;i++){
//	quet tu cuoi len dau
//	strcmp la lenh de so sanh 2 chuoi
			if(strcmp(f,g)>0){
//	i=index-1 la truong hop doi cho o vi tri cuoi cung co nghia la o vi tri head
				if(i=size-1){
					p->next->prev=p->prev;
					p->prev->next=p->next;
					p->next=p->prev;
					head=p;
				}
//	i=0 là truong hop doi cho ngay tai vi tri tail
				else if(i=0){
					p->prev=p->prev->prev;
					p->prev->next=p;
					tail->prev=p;
					tail->next=NULL;
				}
				else{
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
void ItemsPosition::getName(char name[], string fullName){
	for(int i=strlen(fullName)-1;i>=0;i--){
		if(fullName[i]==' '){
			strcpy(name,fullName+1+i);
			break;
		}
	}
}
void ItemsPosition::searchStaffByPos(int pos){
	if(pos>size){
	cout<<"khong co nhan vien nao o vi tri ban can tim!";
	}else{
		Node*p=new Node;
		p=head;
		for(int i=0;i<=size;i++){
		if(i==pos){
			cout<<p;
		}else {
			p=p->next;
		}
	}
	}
}
void ItemsPosition::print(){
	for(Node *i=head; i!=NULL; i=i->next)
	cout<<i->data.hoten;
}

void ItemsPosition::removeStaffByPos(int pos){
//	Node*p=searchStaffByPos(pos);
	if(pos>size){
	cout<<"khong co nhan vien nao o vi tri ban can xoa!";
	}else{
		Node*p=new Node;
		p=head;
		for(int i=0;i<=size;i++){
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
	
}
int main(){
	char name[50]; string fullName[50];
//	int a;
//	cout<<"nhap vi tri lam(a,b,c) nhap tuong ung voi (1,2,3): ";
//	cin>>a;
//	switch (a) {
//		case 1:{
//			ItemsPosition a;
//			break;
//		}
//		case 2:{
//			ItemsPosition b;
//			break;
//		}
//		case 3:{
//			ItemsPosition c;
//			break;
//		}
//		return 0;
//	}
	ItemsPosition a;
//	cout<<"nhap ho ten ten nhan vien: ";
//	cin>>fullName;
	a.addNewStaff(name,fullName);
	a.print();
}
