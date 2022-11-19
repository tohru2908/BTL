#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
struct nhanvien{
	int MSNV;
	char hoten[100];
	int loaiSP;
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
	void removebymsnv(int pos);
	void xoadanhsach();
	void timkiemnguoilamsp(int x);
	void addBefore(NV p, node *y);
	void addAfter(NV p, node *y);
	void topkpi();
	void printt(int sl);
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
	fflush(stdin);
	gets(x.hoten);
	cout<<"loai SP: ";
	fflush(stdin);
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
void dslkk::removebymsnv(int pos){
	node *p=new node;
	node *q=new node;
	p=head;
    while (p!=NULL&&p->data.MSNV!=pos){
    	q=p;
    	p=p->next;
	}
	if(p==head) removefirst();
	else if(p==tail) removelast();
	else if(p==NULL)cout<<"danh sach trong";
	else {
		node* k=new node;
		node* t= new node;
		if(q!=NULL){
			k=q->next;
			if (k!=NULL){
				t=k->next;
				q->next=t;
				t->prev=q;
				if(p==tail); tail=q;
				delete k;
			}
		}
	}
}
   void dslkk::xoadanhsach(){
   for(node *i=head; i!=NULL; i=i->next){
	node*p=head;
	head=p->next;
	delete p;
    }
 tail=NULL;
} 
void dslkk::timkiemnguoilamsp(int x){
	cout<<"nguoi lam san pham la"<<endl;
	for (node* i=head;i!=NULL;i=i->next){
	if(i->data.loaiSP==x)
	cout<<"\t"<<i->data.hoten<<endl;
};}
void dslkk::addBefore(NV p, node *y){
//them node x vao truoc node y;
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
void dslkk::printt(int sl){
	int dem;
	for(node *i=head; dem<sl; i=i->next){
		cout<<i->data.hoten<<"\t"<<i->data.KPI;
		dem++;
	}
}
void dslkk::topkpi(){
	int top;
	cout<<"Moi nhap top KPI:";
	cin>>top;
	dslkk kpi; //tao danh sach moi de thuc hien so sanh
	kpi.head=kpi.tail=createnode(this->head->data); //node dau tien ko can so sanh
	kpi.size=1;
	//bat dau so sanh tu node 2
	for(node *i=this->head->next; i!=NULL; i=i->next){ //kpi node i cua list chính
		for(node *j=kpi.head; j!=NULL; j=j->next){// so sanh voi kpi node j cua list kpi
			if(i->data.KPI>=j->data.KPI) 
			{	kpi.addBefore(i->data,j);
				break;
			}
			if(j==kpi.tail) {kpi.addAfter(i->data,j); break;}
		}
	}
	//xu ly so luong can print
	
	if (top>=kpi.size) top=kpi.size;
	/*neu so luong can orint < size thi in theo size
	VD: can print top 5, nhung chi co 3 node (size=3)=>print theo size*/
	else{//neu so luong can print >=size thi di ktra node tai vi tri top
		node *x=kpi.head; int dem=1;
		while(dem<top){
			x=x->next;
			dem++;
		}
		//bay gio i la node vi tri cuoi bang top 
		
		/*Neu node top co kpi= kpi node sau thi tang top
		Muc dich la lay het nguoi cung kpi
		VD: lay top 3 cua: 23, 43, 51, 23, 19
		Vi co 2 nguoi kpi=23--> print 4 nguoi*/
		while(x->data.KPI==x->next->data.KPI){
			top++;
			x=x->next;
		}
	}
	cout<<"\ntop hang:"<<top<<endl;
	kpi.printt(top);
}
void dslkk::print(){
	if(head==NULL)
	{
		cout<<"danh sach trong"<<endl;
	}
	else{
	for(node *i=head; i!=NULL; i=i->next)
	cout<<i->data.hoten<<"\t"<<i->data.MSNV<<"\t"<<i->data.loaiSP<<"\t"<<endl;}}
int main() {
dslkk l;
NV NV1;
int n;
cout<<"nhap so nhan vien can nhap"<<endl;
cin>>n;
for(int i=0;i<n;i++){
l.insert(NV1);
//l.luong(NV1);
}
int g;
cout<<"nhap msnv can xoa"<<endl;
cin>>g;
l.removebymsnv(g);
l.print();
cout<<"nhap san pham can tim kiem"<<endl;
int x;
cin>>x;
l.timkiemnguoilamsp(x);
l.topkpi();
l.xoadanhsach();
l.print();
}
