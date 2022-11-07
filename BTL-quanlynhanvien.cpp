#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct nhanvien{
	int MSNV;
	char hoten[100];
	char loaiSP[100];
	float KPI;
};
typedef struct nhanvien NV;
struct node{
	NV data;
	node *next;
	node *prev;
};
struct dblist{
	node *head;
	node *tail;
	int size=0;
	dslkk();
	node *createnode(NV x);
	void addlast(NV x);
	void insert(NV x, int pos);
	void removefirst();
	void removelast();
	void remove(int pos);
	void print();
};
typedef struct dblist dslkk;
dslkk::dslkk(){
	head=tail=NULL;
}
node *dslkk::createnode(NV x){
	node *p;
	p = new node;
	if(p==NULL){
		cout<<"not enough space";
		return NULL;
	}
	else {
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
		return p;
	}
}
void dslkk::addlast(){
	if(head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
}

