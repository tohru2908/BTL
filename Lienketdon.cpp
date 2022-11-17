#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct nhanvien {
    char manv[10];
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
void ThemNV (LIST &ds,int m){
printf("\nNHAP THONG TIN NHAN VIEN CAN THEM\n");
    for(int i = 0; i < m; i++){
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
    for(p = ds.pHead; p != ds.pTail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.manv > q->data.manv){
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
void XoaNhanVien(LIST &ds){
    NODE *p, *q;
    char a[10];
    p=ds.pHead;
    q=NULL;
    printf("\nNhap MSNV can xoa: ");
    fflush(stdin);
    gets(a);
    while (p!=NULL)
    {
        if(strcmp(a, p->data.manv)==0)    break;
        else printf("\nKo co nv can xoa.");
        q=p;
        p=p->next;
    }
    if(q!=NULL)
    {
        if(p!=NULL)
        {
            q->next=p->next;
            delete (p);
            if(p==ds.pTail)  ds.pTail=q;
            delete(p);
        }
    }
    else
    {
        ds.pHead=p->next;
        delete(p);
        if(ds.pHead==NULL)  ds.pTail=NULL;
    }
}
void Tim(LIST ds)
{
    NODE *p;
    int dem=0;
    char k[20];
    cout<<"\nNhap ten nv can tim: ";
    fflush(stdin);
    gets(k);
    p=ds.pHead;
    while (p!=NULL)
    {
        if(strcmp(k,p->data.tennv)==0)
		dem++;
        p=p->next;
    }
    if(dem!=0)
    {
            cout<<"\nTim thay nv: ";
			Xuat(ds);
    }
    else cout<<"\nKo tim thay.";
}

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
        cout << "**  4. Xoa thong tin nhan vien theo MSNV             **\n";
        cout << "**  5. Tim thong tin nhan vien theo Ten              **\n";
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
        		cout << "\n1. Sap xep NV theo san pham";
                SapXepSanPham(ds);
                cout<<"\nSap xep nhan vien thanh cong\n!";
                break;
            case 2:
            	cout <<"\n2. Hien thi thong tin nhan vien";
            	Xuat(ds);
            	break;
            case 3:
            	int m;
            	cout<<"NHAP SO NV CAN THEM M: ";
                cin>>n;
            	cout<<"\n3. Them thong nhan vien";
            	ThemNV(ds,n);
            	cout<<"\nThem thong tin thanh cong\n";
            	break;
            case 4:
            	cout<<"\n4. Xoa thong tin nhan vien theo MSNV";
            	XoaNhanVien(ds);
            	cout<<"\nXoa thong tin nhan vien thanh cong\n";
            	Xuat(ds);
            	break;
            case 5:
            	cout<<"\n5. Tim thong tin nhan vien theo Ten";
            	Tim(ds);
            	cout<<"\nThong tin nhan vien can tim\n";
            	break;
}
}
}
