#include<iostream>
#include<string.h>
using namespace std;
struct node{
	int data;
	string ma;
	node *next;
	node *pre;
	
};
struct list{
	node *head;
	node *tail;

	list();
	node *createnode(int x, string y);
	void addAfter(node *x, int vitri);
	void addBefore(node *x, int vitri);
	void insert(int x, string y, int pos);
	node *takeH=head;
	void remove(int pos);
	void printsl(int x);
	void topkpi(int top);
	int size=0;
};
list::list(){
	head=tail=NULL;
};

node *list::createnode(int x, string y){
	node *p=new node();
	p->data=x;
	p->ma=y;
	p->pre=p->next=NULL;
	return p;
}

void list::addBefore(node *p, int vitri){ 
/*them node p vao truoc node l nho con tro pre
VD: a->y->l se thanh a->y->p->l*/
	int dem; node *i=head; node *j;
	while (i!=NULL&&dem<vitri){
		j=i;
		i=i->next;
		dem++;
	}
	if (i!=head) 
	{	i->next->next=p;
		p->pre=i->pre;
	}
	else head=p;
	p->next=i;
	i->pre=p;
}

void list::addAfter(node *p, int vitri){
	/*them node vao sau l
	VD: a->y->l->p*/
	
	int dem; node *i=head;
	while (i!=NULL&&dem<vitri){
		i=i->next;
		dem++;
	}
	if (i!=tail){
		i->next->pre=p;
		p->next=i->next;
	}
	else tail=p;
	p->pre=i;
	i->next=p;
}

void list::insert(int x, string y, int pos){
	node *p=createnode(x,y);
	if (head==NULL) head=tail=p;
	else{
		int dem; node* i=head;
		while (i!=NULL&&dem<pos) {
			i=i->next;
			dem++;
		}
		cout<<"vt hien tai:"<<dem<<endl;
		this->addBefore(p,dem);
		cout<<"done"<<endl;
	}
	size++;
}

/*void list::removefirst(){
	head=head->next;
	size--;
}

void list::removelast(){
	for(node *i=head; i!=NULL; i=i->next){
		if (i->next==tail) {tail=i; tail->next=NULL; break;}
	size--;
	}
}*/

/*void list::remove(int pos){
	if(head==NULL) cout<<"List is empty";
	
	else{
		int dem;
		for (node *i=head; i!=NULL&&dem<pos; i=i->next){
			dem++;
			if (dem==pos){
				 i->next->pre=i->pre;
				 i->pre->next=i->next;
				 delete i;
			}
		}
	}
	size--;
}*/

void list::printsl(int x){
	int dem=0;
	for(node *i=head; i!=NULL&&dem<x; i=i->next){
		cout<<i->ma<<"_"<<i->data<<endl;
		dem++;
	}
}
/*void list::topkpi(int top){
	list kpi;
	
	
	if (top<kpi.size){
		int dem=0; node *i=kpi.takeH;
		while(dem<top) i=i->next;
		//luc nay i la node tai vi tri top
		if(i->data=i->next->data)
			while (i->data>i->next->data){
				top++;
				i=i->next;
			}
	}
	kpi.printsl(top);
	
}*/
int main(){
	list l;
	string x1,x2;
	cout<<"Nhap ma chung 1:";
	cin.ignore();
	getline(cin,x1);
	
	cout<<"Nhap ma chung 2:";
	cin.ignore();
	getline(cin,x2);
	
	l.insert(21,x1,1);
	l.insert(31,x2,1);
	l.insert(5,x2,2);
	l.insert(72,x1,2);
	l.insert(73,x1,3);
	l.insert(93,x2,3);
	l.printsl(l.size);
	//l.topkpi(4);
	
}
