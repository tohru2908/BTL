#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
struct nhanvien{
	char MSNV[1000];
	char fullName[1000];
	char loaiSP[10];
	float KPI;
	long long LHD,total,LCD,LBD;
	char name[1000];
	
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
	void addBefore(NV p, node *y);
	void addAfter(NV p, node *y);
	void insert(NV x);
	void addNewStaff(NV x);
	void searchStaffByPos(int pos);
	void removeStaffByPos(int pos);
	void getName(NV x);
	char takename[1000];
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
void dslkk::addBefore(NV p, node *y){
//them node x co data=p vao truoc node y;
	node *x=createnode(p);
	if (y!=head){
		x->prev=y->prev;
		y->prev->next=x;
	}
	else head=x;
	x->next=y;
	y->prev=x;
	size++;
}

void dslkk::addAfter(NV p, node *y){
	node *x=createnode(p);
	if(tail!=y){
		y->next->prev=x;
		x->next=y->next;
	}
	else tail=x;
	x->prev=y;
	y->next=x;
	size++;
}
void dslkk::insert(NV x){
	if(head==NULL)
		cout<<"danh sach trong\n";

	cout<<"nhap thong tin nhan vien\n";
	cout<<"Nhap MSNV: ";
	cin>>x.MSNV;
	cin.ignore();
	cout<<"Nhap Ho va Ten nhan vien: ";
	gets(x.fullName);
	cout<<"loai SP: ";
	cin>>x.loaiSP;
	getName(x);
	strcpy(x.name,this->takename+0);
	//cout<<"test name:"<<x.name<<endl;
	addNewStaff(x);
}
void dslkk::getName(NV x){
	
	for(int i=strlen(x.fullName)-1;i>=0;i--){
		if(x.fullName[i-1]==' '||i==0){
			strcpy(this->takename,x.fullName+i);
			break;
		}
	}
}

void dslkk::addNewStaff(NV x){
	node *p=createnode(x);
	if (head==NULL) {head=tail=p; size++;}
	
	for (node *i=head;i!=NULL;i=i->next){
		if(strcmp(p->data.name,i->data.name)<0) //xem them ve ham strcmp
			{ addBefore(p->data,i); break;}
		else if(tail==i&&tail!=p) //loai tru tuong hop nhap them node dau tien
			{addAfter(p->data,i); break;};
	}
	

void dslkk::print(){
	for(node *i=head; i!=NULL; i=i->next)
	cout<<i->data.name<<"\t"<<i->data.MSNV<<"\t"<<i->data.loaiSP<<"\t"<<i->data.total<<endl;}
int main(){
	dslkk l;
	NV NV1,NV2,NV3;
	l.insert(NV1);
	l.insert(NV2);
	l.print();
	l.insert(NV3);
	l.print();
}
