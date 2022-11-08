#include <iostream>
using namespace std;
struct NhanVien{
    char MaNV[50];
    char TenNV[50];
    int SanPham;
} nv[100];
void Nhap(int n){
    for(int i=1; i<=n; i++){
        cout<<"\nNhap thong tin nhan vien thu:"<<i;
        
        cout<<"\nNhap ma nhan vien:";
        gets(nv[i].MaNV);
        cout<<"\nNhap ten nhan vien:";
        gets(nv[i].TenNV);
        cout<<"\nNhap loai san pham:";
        cin>>nv[i].SanPham;
    }
}
void Xuat(int n){
    cout<<"\n-----THONG TIN NHAN VIEN----\n";
    for(int i=0; i<n; i++){
        cout<<"MaNV"<<nv[i].MaNV<<"TenNv" <<nv[i].TenNV<<"SanPham" <<nv[i].SanPham;
    }
}
void sapxep(int n){
	for(int i=0; i<n-1; i++){
        for(int j=n-1;j>i;j--){
            if(nv[i].SanPham > nv[j].SanPham){
               swap(nv[i],nv[j]);
            }
        }
    }
}
int main(){
    int n; 
    cout<<"Nhap so nhan vien:";
    cin>>n;
    Nhap(n);
    Xuat(n);
    cout<<"\n--DANH SACH NHAN VIEN SAU KHI SAP XEP--\n";
    sapxep(n);
    Xuat(n);
}
