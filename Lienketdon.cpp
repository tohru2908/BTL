#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct nhanvien {
    int manv;
    char tennv[50];
    char sanpham[20];
    int luong;
    float KPI;
};
typedef struct nhanvien NV;
struct node{
    NV data;
    node * next;
};
typedef struct node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}
int KiemTraRong(LIST ds){
    if (ds.pHead == NULL){
        return 1;
    }
    return 0;
}
NODE* TaoNode(NV x) {
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}
void ChenCuoi (LIST &ds, NODE *p){
    if (ds.pHead==NULL) {
        ds.pHead=p;
        ds.pTail=p;
    }
    else {
        ds.pTail->next=p;
        ds.pTail=p;
    }
}
void Nhap(LIST &ds, int n){
    printf("NHAP THONG TIN NHAN VIEN\n");
    for(int i = 0; i < n; i++){
        NV x;
        cout<<"Nhap ma nhan vien : ";
		fflush(stdin);
		cin>>x.manv;
        cout<<"Nhap ten nhan vien : ";
		fflush(stdin);
		gets(x.tennv);
        cout<<"Nhap san pham : ";
		fflush(stdin);
        cin>>x.sanpham;
        cout<<"Nhap luong: ";
		fflush(stdin);
        cin>>x.luong;
        cout<<"Nhap KPI : ";
		fflush(stdin);
        cin>>x.KPI;
        cout<<"\n \n";
        NODE *p = new NODE;
        p = TaoNode(x);
        ChenCuoi(ds,p);
    }
}
void ThemNV (LIST &ds,int n){
printf("NHAP THONG TIN NHAN VIEN CAN THEM\n");
    for(int i = 0; i < n; i++){
        NV x;
        cout<<"Nhap ma nhan vien : ";
		fflush(stdin);
		cin>>x.manv;
        cout<<"Nhap ten nhan vien : ";
		fflush(stdin);
		gets(x.tennv);
        cout<<"Nhap san pham : ";
		fflush(stdin);
        cin>>x.sanpham;
        cout<<"Nhap luong: ";
		fflush(stdin);
        cin>>x.luong;
        cout<<"Nhap KPI : ";
		fflush(stdin);
        cin>>x.KPI;
        cout<<"\n \n";
        NODE *p = new NODE;
        p = TaoNode(x);
        ChenCuoi(ds,p);
    }
}
void Xuat(LIST ds){
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        cout<< p->data.manv<< "\t"<< p->data.tennv<< "\t"<< p->data.sanpham<< "\t"<< p->data.luong<< "\t"<< p->data.KPI<<"\n";
    }
}
void SapXepSanPham(LIST &ds){
    NODE *p, *q;
    int A=1,B=2,C=3;
    for(p = ds.pHead; p != ds.pTail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.sanpham > q->data.sanpham){
                NV x = p->data;
                p->data = q->data;
                q->data = x; 
            }
        }
    }
    Xuat(ds);
}
void XoaCuoi(LIST &ds)
{
    for(NODE *k = ds.pHead; k != NULL; k = k ->next)
    {
        if(k->next == ds.pTail)
        {
            delete ds.pTail;
            k->next = NULL;
            ds.pTail = k;
        }
    }
    Xuat(ds);
}
void pressAnyKey();
int main(){
    LIST ds;
    int n;
    cout<<"NHAP SO NV CAN NHAP N: ";
    cin>>n;
    KhoiTao(ds);
    Nhap(ds,n);
    cout<<"\nDANH SACH SINH VIEN\n";
    Xuat(ds);
    int key;
    while(true) {
        cout << "CHUONG TRINH QUAN LY NHAN VIEN \n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Sap xep NV theo san pham                      **\n";
        cout << "**  2. Hien thi thong tin nhan vien                  **\n";
        cout << "**  3. Them thong tin nhan vien                      **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
        	case 0:
        		cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
			case 1:
        		cout << "\n1. Sap xep NV theo san pham.";
                SapXepSanPham(ds);
                cout<<"\nSap xep nhan vien thanh cong!";
                pressAnyKey();
                break;
            case 2:
            	cout <<"\n2. Hien thi thong tin nhan vien";
            	Xuat(ds);
            	pressAnyKey();
            	break;
            case 3:
            	cout<<"\n3. Them thong nhan vien";
            	ThemNV(ds,n);
            	cout<<"\nThem thong tin thanh cong";
            	pressAnyKey();
            	break;
}
}
