#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CongTy
{
    private:
    string ten_cong_ty;
    int ma_So_thue;
    int doanh_thu_thang;
    public:
    CongTy(){

    }
    // CongTy(string ten_cong_ty, int ma_So_thue, int doanh_thu_thang)
    // {
    //     this->ten_cong_ty=ten_cong_ty;
    //     this->ma_So_thue=ma_So_thue;
    //     this->doanh_thu_thang=doanh_thu_thang;
    // }
    void nhap()
    {
        cout<<"\n\t NHAP THONG TIN CONG TY"<<endl;
        cin.ignore();
        cout<<"Nhap ten cong ty: ";
        
        getline(cin, ten_cong_ty);
        cout<<"Nhap ma so thue: ";
        cin>>ma_So_thue;
        cout<<"Nhap doanh thu thang: ";
        cin>>doanh_thu_thang;
    }
    
    void xuat()
    {
        cout<<"\n\t XUAT THONG TIN CONG TY"<<endl;
        cout<<"Ten cong ty: "<< ten_cong_ty<<endl;
        cout<<"Ma so thue: "<<ma_So_thue<<endl;
        cout<<"Doanh thu thang: "<<doanh_thu_thang<<endl;
    }


};

class NhanVien
{
    protected:
    string ma_so;
    string name;
    int tel;
    int so_ngay_cong;
    
    public:
    NhanVien(){

    }
    ~NhanVien(){

    }
    NhanVien(string ma_so, string name, int tel, int so_ngay_cong)
    {
        this->ma_so=ma_so;
        this->name=name;
        this->tel=tel;
        this->so_ngay_cong=so_ngay_cong;
        
    }
    virtual void nhap(){
        cout<<"Nhap ma so nhan vien: ";
        cin>>ma_so;
        cout<<"Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Nhap so dien thoai lien he: ";
        cin>>tel;

        cout<<"Nhap so ngay cong: ";
        cin>>so_ngay_cong;
        
    }

    virtual void xuat()
    {
        cout<<"Ma nhan vien: "<<ma_so<<endl;
        cout<<"Ten nhan vien: "<<name<<endl;
        cout<<"So dien thoai: "<<tel<<endl;
        cout<<"So ngay cong: "<<so_ngay_cong<<endl;
        
    }
    string getMa_so()
    {
        return ma_so;
    }
    string getName()
    {
        return name;
    }

    virtual int luong()=0;
};

class  NhanVienThuong:public NhanVien
{    
    private:
    string truong_phong_quan_li;
    public:
    NhanVienThuong(){

    }
    ~NhanVienThuong(){

    }
    NhanVienThuong(string ma_so, string name, int tel, int so_ngay_cong, string truong_phong_quan_li):NhanVien(ma_so,name, tel, so_ngay_cong)
    {
        this->truong_phong_quan_li=truong_phong_quan_li;
    }
    void nhap()
    {  
        cout<<"\n\t NHAP THONG TIN NHAN VIEN THUONG"<<endl;
        NhanVien::nhap();
        cout<<"Nhap truong phong quan li: ";
        cin.ignore();
        getline(cin, truong_phong_quan_li);

    }  

    void xuat()
    {
        cout<<"\n\t XUAT THONG TIN NHAN VIEN THUONG"<<endl;
        NhanVien::xuat();
        cout<<"Truong phong quan li: "<<truong_phong_quan_li<<endl;
    }

    int luong()
    {
        return so_ngay_cong*100;
    }

    string getTruongPhongQL()
    {
        return truong_phong_quan_li;
    }
    


};

class TruongPhong:public NhanVien
{
    private:
    vector<NhanVienThuong> tp;
    public:
    TruongPhong(){

    }
    ~TruongPhong(){

    }
    TruongPhong(string ma_so, string name, int tel, int so_ngay_cong,vector<NhanVienThuong> tp):NhanVien(ma_so, name,tel,  so_ngay_cong)
    {
        this->tp=tp;
    }
    
    // void ds_nhanvienduoiquyen()
    // {
    //     NhanVienThuong x;
    //     if(x.getTruongPhongQL() == name)
    //     {
    //         tp.push_back(x);
    //     }
    // }
   
    void nhap()
    {
        cout<<"\n\t NHAP THONG TIN TRUONG PHONG"<<endl;
        NhanVien::nhap();
        //ds_nhanvienduoiquyen();
    }

    void xuat()
    {
        cout<<"\n\t XUAT THONG TIN QUAN LI"<<endl;
        NhanVien::xuat();
        cout<<"Danh sach ten nhan vien duoi quyen: "<<endl;
        // for(int i=0; i<tp.size(); i++)
        // {
        //     cout<<" Nhan vien thu "<<i+1;
        //     tp[i].getName();
        // }
    }

    int luong()
    {
        return 200*so_ngay_cong+100*tp.size();
    }

};

class GiamDoc:public NhanVien
{
    private:
    double phan_tram;
    public:
    GiamDoc(){

    }
    ~GiamDoc(){

    }
    GiamDoc(string ma_so, string name, int tel, int so_ngay_cong, double phan_tram):NhanVien(ma_so, name, tel, so_ngay_cong)
    {
       this->phan_tram=phan_tram;
    }
    

    void nhap()
    {
        cout<<"\n\t NHAP THONG TIN GIAM DOC"<<endl;
        NhanVien::nhap();
        cout<<"Nhap so pham tram duoc trich: ";
        while(true)
        {
           cin>>phan_tram;
           if(phan_tram > 100.00 || phan_tram < 0.00)
           {
               cout<<"So phan tram khong hop le, xin nhap lai!"<<endl;
           } 
           else 
           {
               break;
           }
        }
    }

    void xuat()
    {
        cout<<"\n\t XUAT THONG TIN GIAM DOC"<<endl;
        NhanVien::xuat();
        cout<<"Phan tram duoc trich: "<<phan_tram<<endl;
    }
 
    int luong()
    {
        return 300*so_ngay_cong;
    }
    
};



int main()
{  

    // Nhập xuất thoong tin công ty
//    CongTy cty;
//    cty.nhap();
//    cty.xuat();



     //Nhập danh sách nhân viên 
    vector <NhanVien *> ds_nhanvien;
    
    int luachon;
    while (true)
    {
        cout<<"\n\n\t\t MENU"<<endl;
        cout<<"\n\t Chon 1 de nhap thong tin nhan vien thuong "<<endl;
        cout<<"\n\t Chon 2 de nhap thong tin truong phong"<<endl;
        cout<<"\n\t Chon 3 de nhap thong tin giam doc"<<endl;
        cout<<"\n\t Chon phim bat ki de ket thuc lenh nhap"<<endl;
        cin>>luachon;
        NhanVien *a= new NhanVienThuong;
        if(luachon==2)
        {
            a=new TruongPhong;   
        } else if(luachon==1)
        {
            a=new NhanVienThuong;   
        } else if(luachon==3)
        {
           a=new GiamDoc; 
        }
        else 
        { 
            break;
        }
        a->nhap();
        ds_nhanvien.push_back(a);
         
    }

    //XUẤT DANH SÁCH NHÂN VIÊN 
      
    // for(int i=0; i<ds_nhanvien.size();i++)
    // {
    //     ds_nhanvien[i]->xuat();
        
    //     cout<<endl;
    // }
    
    
    
    
    
    //PHÂN BỔ NHÂN VIÊN THƯỜNG VÀO TRƯỞNG PHÒNG

//    int luachon;
//    vector<NhanVienThuong> ds_NhanVienThuong;
//    vector<TruongPhong> ds_TruongPhong;
//    NhanVienThuong x;
//    TruongPhong y;
//     while(true)
//     {
//         cout<<"\n\n\t\t NHAP THONG TIN NHAN VIEN"<<endl;
//         cout<<"\n\t Chon 1 de nhap thong tin nhan vien thuong"<<endl;
//         cout<<"\n\t Chon 2 de nhap thong tin truong phong"<<endl;
//         cout<<"\n\t Chon phim bat ki de ket thuc lenh nhap"<<endl;
//         cin>>luachon;
//         if(luachon==1)
//         {   
//             x.nhap();
//             ds_NhanVienThuong.push_back(x);
//         } else if(luachon==2)
//         {
//             y.nhap();
//             ds_TruongPhong.push_back(y);
//         }
//         else
//         {
//             break;
//         }
//     } 

//     for(int i=0; i<ds_TruongPhong.size(); i++)
//     {
//         for(int j=0; j<ds_NhanVienThuong.size(); j++)
//         {  
//             cout<<"Danh sach nhan vien cap duoi cua truong phong "<<ds_TruongPhong[i].getName()<<" : "<<endl;
//             if(ds_TruongPhong[i].getName()==ds_NhanVienThuong[j].getTruongPhongQL())
//             {
                
//                 cout<<ds_NhanVienThuong[j].getName()<<endl;
//             }
//         }
       
//     }






//  THÊM BỚT NHÂN VIÊN
    
//     int luachon;
//     while (true)
//     {
//         cout<<"\n\n\t\t MENU"<<endl;
//         cout<<"\n\t Chon 1 de nhap thong tin nhan vien thuong "<<endl;
//         cout<<"\n\t Chon 2 de nhap thong tin truong phong"<<endl;
//         cout<<"\n\t Chon 3 de nhap thong tin giam doc"<<endl;
//         cout<<"\n\t Chon phim bat ki de ket thuc lenh nhap"<<endl;
//         cin>>luachon;
//         NhanVien *a= new NhanVienThuong;
//         if(luachon==2)
//         {
//             a=new TruongPhong;   
//         } else if(luachon==1)
//         {
//             a=new NhanVienThuong;   
//         } else if(luachon==3)
//         {
//            a=new GiamDoc; 
//         }
//         else 
//         { 
//             break;
//         }
//         a->nhap();
//         ds_nhanvien.push_back(a);
         
//     }
      
//     cout<<"\n\t DANH SACH NHAN VIEN TRUOC KHI THAY DOI"<<endl;
//     for(int i=0; i<ds_nhanvien.size();i++)
//     {  
        
//         ds_nhanvien[i]->xuat();
        
//         cout<<endl;
//     }

//     int lua;
//     string xoa;
    
//     while(true)
//     {
//         cout<<"\n\n\t\t THEM VA XOA NHAN VIEN"<<endl;
//         cout<<"\n\t Chon 1 de them nhan vien"<<endl;
//         cout<<"\n\t Chon 2 de xoa nhan vien"<<endl;
//         cout<<"\n\t Chon phim bat ki de ket thuc"<<endl;
//         cin>>lua;
//         if(lua==1)
//         {
//             int chon;
//         cout<<"\n\t Chon 1 de them thong tin nhan vien thuong "<<endl;
//         cout<<"\n\t Chon 2 de them thong tin truong phong"<<endl;
//         cout<<"\n\t Chon 3 de them thong tin giam doc"<<endl;
        
//         cin>>chon;
//         NhanVien *a= new NhanVienThuong;
//         if(chon==2)
//         {
//             a=new TruongPhong;   
//         } else if(chon==1)
//         {
//             a=new NhanVienThuong;   
//         } else if(chon==3)
//         {
//            a=new GiamDoc; 
//         }
//         else 
//         { 
//             break;
//         }
//         a->nhap();
//         ds_nhanvien.push_back(a);
            

//         } else if(lua==2)
//         {   
//             cout<<"Nhap ma so nhan vien can xoa: ";
//             cin.ignore();
//             getline(cin, xoa);
//             int c;
//             for(int i=0; i<ds_nhanvien.size(); i++)
//             {
//                 if(ds_nhanvien[i]->getMa_so()==xoa)
//                 {
//                     c=i;
                    
//                 }
//             }
//             ds_nhanvien.erase(ds_nhanvien.begin()+c);
            
//         } else 
//         {
//             break;
//         }
//     }
//     cout<<"DANH SACH NHAN VIEN SAU KHI THAY DOI"<<endl;

    
//     for(int i=0; i<ds_nhanvien.size(); i++)
//     {
//         ds_nhanvien[i]->xuat();
//     }
    


//TÍNH TỔNG LƯƠNG CỦA CÔNG TY
// int tong;
// for(int i=0; i<ds_nhanvien.size(); i++)
// {
//    tong += ds_nhanvien[i]->luong();
// }

// cout<<"Tong luong cua cong ty: "<<tong<<endl;


//TÌM NGƯỜI CÓ LƯƠNG CAO NHẤT
// int max=ds_nhanvien[0]->luong();
// for(int i=0; i<ds_nhanvien.size(); i++)
// {
//     if(ds_nhanvien[i]->luong()>max)
//     {
//         max=ds_nhanvien[i]->luong();
//     }
// }

// for(int i=0; i<ds_nhanvien.size(); i++)
// {
// cout<<endl;

//     if(ds_nhanvien[i]->luong()==max)
     
//     cout<<"\n\t NHAN VIEN CO LUONG CAO NHAT "<<endl;
//     cout<<"Ho ten nhan vien: ";
//     cout<<ds_nhanvien[i]->getName()<<endl;
//     cout<<"Ma nhan vien: ";
//     cout<<ds_nhanvien[i]->getMa_so()<<endl;
// }



//SẮP XẾP DANH SACH NHAN VIÊN THEO ABC

for(int i=0; i<ds_nhanvien.size(); i++)
{
    for(j=i+1; j<ds_nhanvien.size(); j++)
    {
        if(strcmp(ds_nhanvien[i]->getName(), ds_nhanvien[j]->getName())>0)
        {
            strcmp(temp, ds_nhanvien[i]);
            strcmp(ds_nhanvien[i], ds_nhanvien[j])
            strcmp(ds_nhanvien[j], temp);
        }
    }
}

cout<<"\n\t DANH SACH NHAN VIEN SAU SAP XEP"<<endl;
for(int i=0; i<ds_nhanvien.size(); i++)
{
    ds_nhanvien[i]->xuat();
}


   
}


