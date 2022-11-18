#include<iostream>
using namespace std;
struct nhanvien{
	int MSNV;
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
	cin>>NV.MSNV;
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
	void xoamsnv(int x);
	void print();
	void xoads();
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
void timkiem::xoamsnv(int x){
	node *p=new node;
   for (node*i=head;i!=NULL; i=i->next){
   	if(i->data.MSNV==x){
   		p->next=i->next;
   		delete i;
   		return;
	   }
	   p=i;
   }}
   void timkiem::xoads(){
   for(node *i=head; i!=NULL; i=i->next){
	node*p=head;
	head=p->next;
	delete p;
} tail=NULL;
	  }   
void timkiem::print(){
	if(head==NULL)
	{
		cout<<"danh sach trong"<<endl;
	}
	else{
	for(node *i=head; i!=NULL; i=i->next){
		cout<<i->data.hoten<<"\t"<<i->data.MSNV<<"\t"<<i->data.loaiSP<<endl;
	}
}}
int main(){
	timkiem l;
	NV a,b,c,d;
	int x, g;
	cout<<"nhan vien a"<<endl;
	Nhap(a);
	cin.ignore();
	cout<<"nhan vien b"<<endl;
	Nhap(b);
	cin.ignore();
	cout<<"nhan vien c"<<endl;	
	Nhap(c);
	cin.ignore();
	cout<<"nhan vien d"<<endl;	
	Nhap(d);
	cin.ignore();
	cout<<"nhap loai san pham can tim"<<endl;
	cin>>x;
	cout<<endl;
    l.addlast(a);
    l.addlast(b);
    l.addlast(c);
    l.addlast(d);
    l.loaisp(x);
    cout<<endl;
    cout<<"nhap ma so nhan vien can xoa";
    cin>>g;
    l.xoamsnv(g) ;
    l.print();
    l.xoads();
    l.print();
}
