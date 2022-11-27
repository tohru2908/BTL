#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stdbool.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef struct nhanvien{
	char MSNV[100];
	char name[100];
	char fullName[1000];
	int loaiSP;
	float KPI;
	long long LHD,total,LCD,LBD;
}NV;
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
	bool duyetMSNV(NV x);
	void addlast(NV x);
	void addBefore(NV p, node *y);
	void addAfter(NV p, node *y);
	char takename[1000];
	void getName(NV x);
	void addNewStaff(NV x);
	void insert(NV x);

	
	void removefirst();
	void removelast();
	void removebymsnv(char pos[]);
	void xoadanhsach();
	
	void timsp(int x);
	void timten();
	void timms();
	void luongkhoang();
	void topkpi();
	void topluong();

	void printt(int sl);
	void print();
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

bool dslkk::duyetMSNV(NV x){

	if (x.MSNV[0]=='-'){
		cout<<"MSNV khong hop le, moi nhap lai\n";
		return true;
	}

	for (node *i=head;i!=NULL;i=i->next){
		if(strcmp(i->data.MSNV,x.MSNV)==0){
			cout<<"MSNV bi trung, moi nhap lai\n";
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
		if (duyetMSNV(x)==false) duyet=1;
	}
	cout<<"Nhap Ho va Ten nhan vien: ";
	cin.ignore();
	gets(x.fullName);
	cout<<"Loai SP: ";
	cin>>x.loaiSP;
	cout<<"Luong theo hop dong (>0): ";
	cin>>x.LHD;
	while(x.LHD<=0){
		cout<<"Moi nhap lai luong theo hop dong (>0): ";
		cin>>x.LHD;
	}
	cout<<"KPI: ";
	cin>>x.KPI;
	x.LCD=x.LHD*0.25;
	x.LBD=x.LHD*0.75;
	x.total=x.LCD+(x.KPI*x.LBD);
	
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
void dslkk::removebymsnv(char pos[]){
	node *p=new node;
	node *q=new node;
	p=head;
    while (p!=NULL&&strcmp(pos,p->data.MSNV)!=0){
    	q=p;
    	p=p->next;
	}
	if(p==head) removefirst();
	else if(p==tail) removelast();
	else if(p==NULL)cout<<"MSNV khong ton tai\n";
	else {
			p->prev->next=p->next;
			p->next->prev=p->prev;
			delete p;
				cout<<"Da xoa nhan vien\n";
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
void dslkk::timsp(int x){
	int t=0;
	if(head==NULL){
		cout<<"Danh sach trong";
	}
	else {
		cout<<"Nguoi lam san pham la"<<endl;
		for (node* i=head;i!=NULL;i=i->next){
			if(i->data.loaiSP==x){
				cout<<"\t"<<i->data.fullName<<endl;
				t=1;
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
		cout<<i->data.fullName<<"\tMSNV:"<<i->data.MSNV<<"\tKPI:"<<i->data.KPI<<"\t\tLuong:\t"<<i->data.total<<endl;
		dem++;
	}
}
void dslkk::topkpi(){
	int top;
	cout<<"Moi nhap top KPI muon xem:";
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
	cout<<"\nCac nhan vien co KPI top "<<top<<":"<<endl;
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
	kpi.printt(top);
	kpi.xoadanhsach();	
}
void dslkk::topluong(){
	int top;
	cout<<"Moi nhap top luong muon xem:";
	cin>>top;
	dslkk toplg; 
	toplg.head=toplg.tail=createnode(this->head->data); 
	toplg.size=1;
	for(node *i=this->head->next; i!=NULL; i=i->next){ 
		for(node *j=toplg.head; j!=NULL; j=j->next){
			if(i->data.total>=j->data.total) 
			{	toplg.addBefore(i->data,j);
				break;
			}
			if(j==toplg.tail) {toplg.addAfter(i->data,j); break;}
		}
	}
	cout<<"\nCac nhan vien co luong top "<<top<<":"<<endl;
	if (top>=toplg.size) top=toplg.size;
	else{
		node *x=toplg.head; int dem=1;
		while(dem<top){
			x=x->next;
			dem++;
		}
		while(x->data.total==x->next->data.total){
			top++;
			x=x->next;
		}
	}
	toplg.printt(top);
	toplg.xoadanhsach();	
}
void dslkk::print(){
	if(head==NULL)
	{
		cout<<endl;
		cout<<"Danh sach trong"<<endl;
	}
	else{
		for(node *i=head; i!=NULL; i=i->next)
		cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN  "<<i->data.MSNV<<"\t"<<"SAN PHAM  "<<i->data.loaiSP<<"\tKPI:  "<<i->data.KPI<<"\t"<<"LUONG \t"<<i->data.total<<endl;
	}
}
void dslkk::timten(){
	node *i;
    int dem=0;
    char k[100];
    cout<<"\nNhap ten nv can tim: ";
    cin.ignore();
    gets(k);
    cout<<"Thong tin nguoi can tim la"<<endl;
	for (node* i=head;i!=NULL;i=i->next){
	if(strcmp(k,i->data.fullName)==0||strcmp(k,i->data.name)==0){
		dem=1;
		cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN ""\t"<<i->data.MSNV<<"\t"<<"\tSAN PHAM\t"<<i->data.loaiSP<<"\t"<<"\tKPI"<<i->data.KPI<<"\t"<<"LUONG \t"<<i->data.total<<endl;
   }
}
   if(dem==0) cout<<"Ten nhan vien khong ton tai"<<endl;
   
}
void dslkk::timms(){
	node *i;
    int dem=0;
    char b[100];
    cin.ignore();
    cout<<"\nNhap msnv can tim: ";
    cin>>b;
    cout<<"Thong tin nguoi can tim la"<<endl;
    
	for (node* i=head;i!=NULL;i=i->next){
	if(strcmp(i->data.MSNV,b)==0){
		dem=1;
		cout<<"TEN\t"<<i->data.fullName<<"\t"<<"MA SO NHAN VIEN \t"<<i->data.MSNV<<"\tSAN PHAM  "<<i->data.loaiSP<<"\t KPI"<<i->data.KPI<<"\tLUONG \t"<<i->data.total<<endl;
   }
}
   if(dem==0) cout<<"Khong co nguoi lam san pham do"<<endl;
   
}
void dslkk::addlast(NV x){
	node *p=createnode(x);
	if (head==NULL) head=tail=p;
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;	
	}
	size++;
}
void dslkk::luongkhoang(){
	int khoangdau;
	int khoangcuoi;
	cout<<"\nmoi nhap khoang dau cua luong ban muon loc: ";
	cin>>khoangdau;
	cout<<"\nmoi nhap khoang cuoi cua luong ban muon loc: ";
	cin>>khoangcuoi;
	dslkk total;
	for(node *i=this->head; i!=NULL; i=i->next){
		if(i->data.total>=khoangdau&&i->data.total<=khoangcuoi){
			total.addlast(i->data);
		}
	}
	total.print();
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
int main() {
	dslkk l;
	NV NV1;
	int n,b;
	
	srand(time(NULL));

	int key;
	    while(true) {
	    	fflush(stdin);fflush(stdin);
	    	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout <<endl<<"            CHUONG TRINH QUAN LY NHAN VIEN \n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "*************************MENU**************************\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  1. Hien thi danh sach nhan vien                  **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  2. Them nhan vien moi                            **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  3. Tim thong tin nhan vien                       **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  4. Tim nhan vien trong top                       **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  5. Xoa thong tin nhan vien                       **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  6. Xoa danh sach                                 **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "**  0. Thoat                                         **\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "*******************************************************\n";
	        SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        cout << "Nhap tuy chon: ";
	        cin >> key;
	        switch(key){
			 	case 0:
			 		SET_COLOR(rand() % (9 - 1 + 1) + 1);
	        	    cout << "\nBan da chon thoat chuong trinh!";
	                
	            return 0;	
	            case 1: 
	            SET_COLOR(rand() % (9 - 1 + 1) + 1);
				    cout<<"Thong tin nhan vien "<<endl;
				    l.print();
				    break;
				case 2:
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout<<"NHAP SO NV CAN THEM M: ";
	                cin>>n;
	            	while(n<0) {
	            		SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            		cout<<"Moi nhap lai M(M>0): ";
		                cin>>n;}
		                
				    for(int i=0;i<n;i++){
	                	l.insert(NV1);
	                	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                    cout<<"Them thong tin thanh cong\n";
	                    }      
					break;
				
				case 3:
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
					cout << "*************************MENU**************************\n";
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout << "**  1. Tim thong tin nhan vien theo ten              **\n";
	            	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**  2. Tim thong tin nhan vien theo MS               **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**  3. Tim thong tin nhan vien lam loai san pham     **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**  4. Tim danh sach nhan vien trong khoang luong    **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "*******************************************************\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "Nhap tuy chon: ";
	                cin >> b;
				    switch(b){
				    	case 1:
				    		l.timten();
				    		break;
				    	case 2:
				    		l.timms();
				    		break;
				    	case 3:
				    		SET_COLOR(rand() % (9 - 1 + 1) + 1);
				    		cout<<"Nhap loai san pham can tim nhan vien"<<endl;
							cin>>b;
							l.timsp(b);
							break;
						case 4:
							l.luongkhoang();
							break;
					}
					break;
				case 4:
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout << "*************************MENU**************************\n";
	            	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout << "**     1. Tim top KPI                                **\n";
	            	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**     2. Tim top luong                              **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "*******************************************************\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "Nhap tuy chon: ";
	                cin >> b;
	                switch(b){
	                	case 1:
	                		l.topkpi();
	                		break;
	                	case 2:
	                		l.topluong();
	                		break;
	                }
	                break;
				case 5:
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout << "*************************MENU**************************\n";
	            	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	            	cout << "**  1. Xoa thong tin nhan vien o vi tri dau          **\n";
	            	SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**  2. Xoa thong tin nhan vien o vi tri cuoi         **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "**  3. Xoa thong tin nhan vien theo MSNV             **\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "*******************************************************\n";
	                SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                cout << "Nhap tuy chon: ";
	                cin >> b;
	                int sure;
	                
	                switch(b){
	                	case 1:
	                		SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                		cout<<"Ban co chac se xoa nhan vien nay?\n 1. Co \t2. Khong\n";
	                		
	                		cin>>sure;
	                		if(sure==1){
		                		l.removefirst();
		                		SET_COLOR(rand() % (9 - 1 + 1) + 1);
		                		cout<<"Xoa thanh cong\n";
		                	}
	                		break;
	                	case 2:
	                		SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                		cout<<"Ban co chac se xoa nhan vien nay?\n 1. Co \t2. Khong\n";
	                		cin>>sure;
	                		if(sure==1){
		                		l.removelast();
		                		SET_COLOR(rand() % (9 - 1 + 1) + 1);
		                		cout<<"Xoa thanh cong\n";
		                	}
	                		break;
	                	case 3:
	                		SET_COLOR(rand() % (9 - 1 + 1) + 1);
	                		cout<<"Nhap MSNV can xoa"<<endl;
					        char h[100];
					        cin>>h;
					        SET_COLOR(rand() % (9 - 1 + 1) + 1);
					        cout<<"Ban co chac se xoa nhan vien nay?\n 1. Co \t2. Khong\n";
	                		cin>>sure;
	                		if(sure==1)  l.removebymsnv(h);
					        break;
					    }
					break;
				
				case 6:
					SET_COLOR(rand() % (9 - 1 + 1) + 1);
					cout<<"Ban co chac muon xoa toan bo danh sach?\n 1. Co \t2. Khong\n";
	                cin>>sure;
	                if(sure==1){
						l.xoadanhsach();
						SET_COLOR(rand() % (9 - 1 + 1) + 1);
				    	cout<<"Ban da xoa toan bo danh sach nhan vien"<<endl;
				    }
				    break;
				}
		}
}
