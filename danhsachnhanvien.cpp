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
	
	luong(x);
}
void dslkk::getName(NV x){
	
	for(int i=strlen(x.fullName)-1;i>=0;i--){
		if(x.fullName[i]==' '){
			strcpy(this->takename,x.fullName+1+i);
			//cout<<"test name:"<<x.name<<endl;
			break;
		}
	}
}
void dslkk::addNewStaff(NV x){
	char f[1000]="",g[1000]="";
	node *p=createnode(x);
//	tao node p nam o vi tri cuoi

	if (tail!=NULL){
	tail->next=p;
	p->prev=tail;}
	tail=p;
	size++;
//	strcpy(f,p->data.name);
//	strcpy(g,p->prev->data.name);
//	danh sach co nhieu hon 1 phan tu thi bat dau cho sap xep
	if(size>=2){
		for(int i=0;i<size;i++){
//	quet tu cuoi len dau
//	strcmp la lenh de so sanh 2 chuoi
			if(strcmp(p->data.name,p->prev->data.name)>0){
//	i=index-1 la truong hop doi cho o vi tri cuoi cung co nghia la o vi tri head
				if(i==size-1){
					//if(p->next!=NULL){
					p->next->prev=p->prev;
					p->prev->next=p->next;
					p->next=p->prev;
					head=p;
				}
//	i=0 l? truong hop doi cho ngay tai vi tri tail
				else if(i==0){
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
			}else if(i==0){
				tail=p;
				break;
			}else{
				break;
			};
		}
	}
	else head=tail=p;
}
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
void dslkk::searchStaffByPos(int pos){
	if(pos>size){
	cout<<"khong co nhan vien nao o vi tri ban can tim!";
	}else{
		node*p=new node;
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
void dslkk::removeStaffByPos(int pos){
//	Node*p=searchStaffByPos(pos);
	if(pos>size){
	cout<<"khong co nhan vien nao o vi tri ban can xoa!";
	}else{
		node*p=new node;
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
