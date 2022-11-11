#include<iostream>
using namespace std;
struct nhanvien{
	char MSNV[1000];
	char hoten[100];
	int loaiSP;
	float KPI;
	long long LHD,total,LCD,LBD;
};typedef struct nhanvien NV;
void Nhap(nhanvien&NV) {
	cout << "Nhap ho ten: ";
	fflush(stdin);
    gets(NV.hoten); 
	cout << "Nhap MSNV: ";
	fflush(stdin);
	gets( NV.MSNV);
	cout << "Nhap Loai San Pham: ";
    cin>>NV.loaiSP;
};
struct node{
	NV data;
	node *next;
	node *prev;
};
struct timkiem {
	node *head;
	node *tail;
	int size=0;
	timkiem();
	node *createnode(NV x);
	void addlast(NV x);
	void loaisp(int x);
};
timkiem::timkiem(){
	head=tail=NULL;
    } 
node *timkiem::createnode(NV x){
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
};
void timkiem ::addlast(NV x){
	node *p=createnode(x);
	if (head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;
	};size++;
}
void timkiem::loaisp(int x){
	for (node* i=head;i!=NULL;i=i->next){
	if(i->data.loaiSP==x)
	cout<<"\t"<<i->data.hoten;
};}

int main(){
	timkiem l;
	NV a,b,c,d;
	int x;
	cout<<"nhan vien a"<<endl;
	Nhap(a);
	cout<<"nhan vien b"<<endl;
	Nhap(b);
	cout<<"nhan vien c"<<endl;	
	Nhap(c);
	cout<<"nhan vien d"<<endl;	
	Nhap(d);
	cout<<"nhap loai san pham can tim"<<endl;
	cin>>x;
    l.addlast(a);
    l.addlast(b);
    l.addlast(c);
    l.addlast(d);
    l.loaisp(x); 
}

