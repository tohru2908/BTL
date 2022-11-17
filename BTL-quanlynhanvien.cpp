#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
struct nhanvien{
	char MSNV[1000];
	char hoten[100];
	char loaiSP[10];
	float KPI;
	long long LHD,total,LCD,LBD;
};
typedef struct nhanvien NV;
struct node{
	NV data;
	node *next;
	node *prev;
};
struct dslkk{
	node *head;
	node *tail;
	int size=0;
	dslkk();
	node *createnode(NV x);
	void addlast(NV x);
	void insert(NV x);
	void removefirst();
	void removelast();
	void remove(int pos);
	void print();
	node* luong(NV x);
};
dslkk::dslkk(){
	head=tail=NULL;
}
node *dslkk::createnode(NV x){
	node *p=new node;
	if (p==NULL){
		cout<<"khong du bo nho";
		return NULL;
	}
	else {
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
		return p;
	}
}
void dslkk::addlast(NV x){
	node *p=createnode(x);
	p=luong(x);
	if (head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;
	};size++;
}
//void ItemsPosition::addNewStaff(char Name[], char fullName[]){
//	Node *p= new Node;
//	index++;
//	for(int i=0;i<index;i++){
//		for(int j=i+1;j<index;j++){
//			if(strcmp(p,p->next)>0&&p->next!=NULL){
//				p->next=p->prev;
//				p=p->next->next;
//			}
//			else{
//				p=p->next;
//			}
//		}
//	}
//}
node* dslkk::luong(NV x){
	node*p=createnode(x);
	cout<<"luong theo hop dong: ";
	cin>>p->data.LHD;
	cout<<"KPI: ";
	cin>>p->data.KPI;
	p->data.LCD=p->data.LHD*0.25;
	p->data.LBD=p->data.LHD*0.75;
	p->data.total=p->data.LCD+(p->data.KPI*p->data.LBD);
	return p;
}
void dslkk::insert(NV x){
	if(head==NULL)
		cout<<"danh sach trong\n";

	cout<<"nhap thong tin nhan vien\n";
	cout<<"Nhap MSNV: ";
	cin>>x.MSNV;
	cin.ignore();
	cout<<"Nhap Ho va Ten nhan vien: ";
	gets(x.hoten);
	cout<<"loai SP: ";
	cin>>x.loaiSP;
	addlast(x);
}


void dslkk::removefirst(){
	node *p=head;
	head=head->next;
	head->prev = NULL;
	size--;
	if (head==NULL){
		tail=NULL;
		p->next=NULL;
		delete p;
	}
}
void dslkk::removelast(){
	node *p=tail;
	tail=tail->prev;
	tail->next=NULL;
	size--;
	if (head==NULL){
		tail=NULL;
		p->next=NULL;
		delete p;
	}
}
void dslkk::print(){
	for(node *i=head; i!=NULL; i=i->next)
	cout<<i->data.hoten<<"\t"<<i->data.MSNV<<"\t"<<i->data.loaiSP<<"\t"<<i->data.total;}
int main() {
dslkk l;
NV NV1;
l.insert(NV1);
//l.luong(NV1);
l.print();

}
