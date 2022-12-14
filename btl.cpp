#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stdbool.h>
using namespace std;
struct nhanvien{
	int MSNV;
	char name[100];
	char fullName[1000];
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
	bool duyetMSNV(NV x);
	void addNewStaff(NV x);
	void insert(NV x);
	void removefirst();
	void removelast();
	void removebymsnv(int pos);
	void xoadanhsach();
	void timkiemnguoilamsp(int x);
	void timten();
	void timms();
	void addBefore(NV p, node *y);
	void addAfter(NV p, node *y);
	void topkpi();
	char takename[1000];
	void getName(NV x);
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
		cout<<"Khong du bo nho";
		return NULL;
	}
	else {
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
		return p;
	}
}
node* dslkk::luong(NV x){
	node*p=createnode(x);
	cout<<"Luong theo hop dong: ";
	cin>>p->data.LHD;
	cout<<"KPI: ";
	cin>>p->data.KPI;
	p->data.LCD=p->data.LHD*0.25;
	p->data.LBD=p->data.LHD*0.75;
	p->data.total=p->data.LCD+(p->data.KPI*p->data.LBD);
	return p;
}
bool dslkk::duyetMSNV(NV x){
	node *p= createnode(x);
	for (node *i=head;i!=NULL;i=i->next){
		if(i->data.MSNV==p->data.MSNV){
			return true;
		}
	}
	return false;
}
void dslkk::insert(NV x){
	cout<<"Nhap thong tin nhan vien\n";
	int duyet=0;
	while (duyet==0){
		cout<<"Nhap MSNV: ";
		cin>>x.MSNV;
		cin.ignore();
		if (duyetMSNV(x)) 
			cout<<"MSNV bi trung, moi nhap lai\n";
		else duyet=1;
	}
	cout<<"Nhap Ho va Ten nhan vien: ";
	cin.ignore();
	gets(x.fullName);
	cout<<"Loai SP: ";
	cin>>x.loaiSP;
	cin.ignore();
	getName(x);
	strcpy(x.name,this->takename+0);
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
	p=luong(x);
	if (head==NULL) {head=tail=p; size++;}
	
	for (node *i=head;i!=NULL;i=i->next){
		if(strcmp(p->data.name,i->data.name)<0)
			{ addBefore(p->data,i); break;}
		else if(tail==i&&tail!=p) 
			{addAfter(p->data,i); break;};
	}
	
}
void dslkk::removefirst(){
	if(head==NULL)
	{
		cout<<endl;
		cout<<"Danh sach trong"<<endl;}
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
	if(head==NULL)
	{
		cout<<endl;
		cout<<"Danh sach trong"<<endl;}
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
	else if(p==NULL)cout<<"Danh sach trong";
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
int t=0;
	if(head==NULL){
		cout<<"Danh sach trong";
	}
	else {
	cout<<"Nguoi lam san pham la"<<endl;
	for (node* i=head;i!=NULL;i=i->next){
	if(i->data.loaiSP==x){
	cout<<"\t"<<i->data.fullName<<endl;
	t++;
   }
   }
   if(t==0) cout<<"Khong co nguoi lam san pham do"<<endl;
}
}

void dslkk::addBefore(NV p, node *y){
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
		cout<<i->data.fullName<<"\t"<<i->data.KPI<<endl;
		dem++;
	}
}
void dslkk::topkpi(){
	int top;
	cout<<"Moi nhap top KPI:";
	cin>>top;
	dslkk kpi; 
	kpi.head=kpi.tail=createnode(this->head->data); 
	kpi.size=1;
	for(node *i=this->head->next; i!=NULL; i=i->next){ 
		for(node *j=kpi.head; j!=NULL; j=j->next){
			if(i->data.KPI>=j->data.KPI) 
			{	kpi.addBefore(i->data,j);
				break;
			}
			if(j==kpi.tail) {kpi.addAfter(i->data,j); break;}
		}
	}
	if (top>=kpi.size) top=kpi.size;
	else{
		node *x=kpi.head; int dem=1;
		while(dem<top){
			x=x->next;
			dem++;
		}
		while(x->data.KPI==x->next->data.KPI){
			top++;
			x=x->next;
		}
	}
	cout<<"\nTop hang:"<<top<<endl;
	kpi.printt(top);
}
void dslkk::print(){
	if(head==NULL)
	{
		cout<<endl;
		cout<<"Danh sach trong"<<endl;
	}
	else{
	for(node *i=head; i!=NULL; i=i->next)
	cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN ""\t"<<i->data.MSNV<<"\t"<<"SAN PHAM\t"<<i->data.loaiSP<<"\t"<<"\tKPI"<<i->data.KPI<<"\t"<<"LUONG \t"<<i->data.total<<endl;}}
void dslkk::timten(){
	node *i;
    int dem=0;
    char k[20];
    cout<<"\nNhap ten nv can tim: ";
    cin.ignore();
    gets(k);
    cout<<"Thong tin nguoi can tim la"<<endl;
	for (node* i=head;i!=NULL;i=i->next){
	if(strcmp(k,i->data.fullName)==0){
	cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN ""\t"<<i->data.MSNV<<"\t"<<"SAN PHAM\t"<<i->data.loaiSP<<"\t"<<"\tKPI"<<i->data.KPI<<"\t"<<"LUONG \t"<<i->data.total<<endl;
   }
}
   if(strcmp(k,i->data.fullName)==0) cout<<"Khong co nguoi lam san pham do"<<endl;
   
}
void dslkk::timms(){
	node *i;
    int dem=0;
    int b;
    cout<<"\nNhap msnv can tim: ";
    cin.ignore();
    cin>>b;
    cout<<"Thong tin nguoi can tim la"<<endl;
	for (node* i=head;i!=NULL;i=i->next){
	if(i->data.loaiSP==b){
	cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN ""\t"<<i->data.MSNV<<"\t"<<"SAN PHAM\t"<<i->data.loaiSP<<"\t"<<"\tKPI"<<i->data.KPI<<"\t"<<"LUONG \t"<<i->data.total<<endl;
   }
}
   if(i->data.loaiSP!=b) cout<<"Khong co nguoi lam san pham do"<<endl;
   
}
int main() {
dslkk l;
NV NV1;
int n;
cout<<"NHAP SO NHAN VIEN CAN NHAP "<<endl;
cin>>n;
if(n>=0){
for(int i=0;i<n;i++){
l.insert(NV1);
cout<<"Nhap thong tin thanh cong\n";
}
}
while(n<0){
	cout<<"Moi nhap lai N(N>0): ";
	cin>>n;
	l.insert(NV1);
	cout<<"Nhap thong tin thanh cong\n";
}
int key;
    while(true) {
        cout << "            CHUONG TRINH QUAN LY NHAN VIEN \n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Hien thi danh sach nhan vien                  **\n";
        cout << "**  2. Tim NV lam san pham                           **\n";
        cout << "**  3. Tim thong tin nhan vien                       **\n";
        cout << "**  4. Them nhan vien moi                            **\n";
        cout << "**  5. Xoa thong tin nhan vien                       **\n";
        cout << "**  6. Tim top KPI                                   **\n";
        cout << "**  7. Xoa danh sach                                 **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
		 	case 0:
        	    cout << "\nBan da chon thoat chuong trinh!";
                
            return 0;	
            case 1: 
			    cout<<"Thong tin nhan vien "<<endl;
			    l.print();
			    break;
			case 2:
				cout<<"Nhap loai san pham can tim nhan vien"<<endl;
				int g;
				cin>>g;
				l.timkiemnguoilamsp(g);
				break;
			case 3:
				int k;
				cout << "*************************MENU**************************\n";
            	cout << "**  1. Tim thong tin nhan vien theo ten              **\n";
                cout << "**  2. Tin thonh tin nhan vien theo MS               **\n";
                cout << "*******************************************************\n";
                cout << "Nhap tuy chon: ";
                cin >> k;
			    switch(k){
			    	case 1:
			    		l.timten();
			    		break;
			    	case 2:
			    		l.timms();
			    		break;
				}
				break;
			case 4:
				int m;
            	cout<<"NHAP SO NV CAN THEM M: ";
                cin>>m;
                if (m>0){
            	for(int i=0;i<m;i++){
                l.insert(NV1);
                cout<<"Them thong tin thanh cong\n";
            	}
			}
            	while(m<0) {
            		cout<<"Moi nhap lai M(M>0): ";
	                cin>>m;
			        for(int i=0;i<m;i++){
                    l.insert(NV1);
                    cout<<"Them thong tin thanh cong\n";
                    }      
			}
				break;
			case 5:
            	int b;
            	cout << "*************************MENU**************************\n";
            	cout << "**  1. Xoa thong tin nhan vien o vi tri dau          **\n";
                cout << "**  2. Xoa thong tin nhan vien o vi tri cuoi         **\n";
                cout << "**  3. Xoa thong tin nhan vien theo MSNV             **\n";
                cout << "*******************************************************\n";
                cout << "Nhap tuy chon: ";
                cin >> b;
                switch(b){
                	case 1:
                		l.removefirst();
                		cout<<"Xoa thanh cong\n";
                		break;
                	case 2:
                		l.removelast();
                		cout<<"Xoa thanh cong\n";
                		break;
                	case 3:
                		cout<<"Nhap MSNV can xoa"<<endl;
				        int h;
				        cin>>h;
				        l.removebymsnv(h);
				        break;
				    }
				break;
			case 6:
				l.topkpi();
				break;
			case 7:
				l.xoadanhsach();
			    cout<<"Ban da xoa toan bo danh sach nhan vien"<<endl;
			    break;
			}
	}
}
