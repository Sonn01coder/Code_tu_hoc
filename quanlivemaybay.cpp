#include <iostream>
#include <string>

#include <vector>

using namespace std;

class KhachHang
{
	private:
		string maKhachHang;
		string name;
		string add;
		int tel;
	   public:
		KhachHang(){
		}
		~KhachHang(){
		}
		KhachHang(string maKhachHang, string name, string add, int tel)
		{
			this->maKhachHang=maKhachHang;
			this->name=name;
			this->add=add;
			this->tel=tel;
		}
		void nhap()
		{
			cout<<"\n\n\t\t NHAP THONG TIN KHACH HANG "<<endl;
			cout<<"Nhap ma khach hang: ";
			cin>>maKhachHang;
			
			cout<<"Nhap ten khach hang: ";
			cin.ignore();
			getline(cin, name);
			cout<<"Nhap dia chi khach hang: ";
			cin.ignore();
			getline(cin, add);
			cout<<"Nhap so dien thoai lien he: ";
			cin>>tel;
		}
		
		void display()
		{
			cout<<"\n\n\t\t XUAT THONG TIN KHACH HANG "<<endl;
			cout<<"Ma khach hang: "<<maKhachHang<<endl;
			cout<<"Ten khach hang: "<<name<<endl;
			cout<<"Dia chi: "<<add<<endl;
			cout<<"Dien thoai lien he: "<<tel<<endl;
		}
		string getMaKhachHang(){
			return maKhachHang;
		}
		
		
};

class Time
{
	private:
		int hour;
		int minute;
	
	public:
		Time(){
		}
		Time(int hour, int minute)
		{
			this->hour=hour;
			this->minute=minute;
        }
		
		void nhap()
		{
			
			cout<<"Nhap gio bay: ";
			cin>>hour;
			cout<<"Nhap phut bay: ";
			cin>>minute;
		}
		
		void display()
		{
			cout<<"Thoi gian bay: "<<hour<<"h"<<minute<<"p"<<endl;
		}
		int getHour()
		{
			return hour;
		}
		int getMinute()
		{
			return minute;
		} 
		
};

class Date
{
	private:
		int day;
		int month;
		int year;
	public:
		Date(){
		}
		~Date(){
		}
		Date(int day, int month, int year)
		{
			this->day=day;
			this->month=month;
			this->year=year;
		}
		void nhap()
		{
			
			cout<<"Nhap ngay: ";
			cin>>day;
			cout<<"Nhap thang: ";
			cin>>month;
			cout<<"Nhap nam: ";
			cin>>year;
		}
		
		void display()
		{
			cout<<"Ngay bay: "<<day<<"/"<<month<<"/"<<year<<endl;
		}
		
		int getDay()
		{
			return day;
		}
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
	}
		
		
};

class Ve
{
    private:
    	Time time;
    	Date date;
    	string mave;
		int soluong;
		int soluongdaban;
		
		int gia;
	public:
	    Ve(){
		}
		~Ve(){
		}
		Ve(Time time, Date date, string mave, int soluong, int soluongdaban, int gia)
		{
			this->time=time;
			this->date=date;
			this->mave=mave;
			this->soluong=soluong;
			this->soluongdaban=soluongdaban;
			this->gia=gia;
		}	
		int getsoluong()
		{
			return soluong;
		}
		int getsoluongdaban()
		{
			return soluongdaban;	
		}
		void nhap()
		{
			
			time.nhap();
			
			date.nhap();
			cout<<"Nhap ma ve: ";
			cin>>mave;
			cout<<"Nhap so luong ve: ";
			cin>>soluong;
			cout<<"Nhap so luong ve da ban: ";
			cin>>soluongdaban;
			cout<<"Gia ve: ";
			cin>>gia;
		}
		
		void display()
		{
			cout<<"Ma ve: "<<mave<<endl;
		    time.display();
		    date.display();
		    if(soluongdaban<soluong)
		    {
		    	cout<<"Tinh trang: Con"<<endl;
			} else 
			{
				cout<<"Tinh trang: Da het"<<endl;
			}
		    cout<<"So luong ve da ban: "<<soluongdaban<<"/"<<soluong<<endl;
		    cout<<"Gia ve: "<<gia<<endl;
				
		}
		
		int getGia(){
			return gia;
		}
		string getmave(){
			return mave;
		}
};

class VeMayBay:public Ve, Date, Time
{
	private: 
	    string tenchuyen;
	    int mamaybay;
	public:
		VeMayBay(){
			}
		~VeMayBay(){
			}
		VeMayBay(Time time, Date date, string mave, int soluong, int soluongdaban, int gia, string tenchuyen,  int mamaybay):Ve(time, date, mave, soluong, soluongdaban, gia)
		{
		    this->tenchuyen=tenchuyen;
			this->mamaybay=mamaybay;
		}
		void nhap()
		{
			cout<<"\n\n\t\t NHAP THONG TIN VE MAY BAY"<<endl;
			cin.ignore();
			cout<<"Nhap ten chuyen bay: ";
		getline(cin, tenchuyen);
			Ve::nhap();
			cout<<"Nhap ma may bay: ";
			cin>>mamaybay;
			
			
		}
        
        void display()
        {
        	cout<<"\n\n\t\t THONG TIN VE MAY BAY"<<endl;
        	cout<<"Ten chuyen bay: "<<tenchuyen<<endl;
        	cout<<"Ma may bay: "<<mamaybay<<endl;
			Ve::display();
			
		}
        
//        vector<VeMayBay> vemaybayy(vector<VeMayBay> v)
//        {
//        	
//        	for(int i=0; i<v.size()-1;i++)
//        	{
//        		for(int j=i+1; j<v.size(); j++)
//        		{
//        			if(v[i].getYear()>v[j].getYear())
//        			{
//        				swap(v[i], v[j]);
//					} else if(v[i].getYear()==v[j].getYear())
//					{
//						if(v[i].getMonth()>v[j].getMonth())
//        			{
//        				swap(v[i], v[j]);
//					} else if(v[i].getMonth()==v[j].getMonth()){
//						if(v[i].getDay()>v[j].getDay())
//        			{
//        				swap(v[i], v[j]);
//					} else if(v[i].getDay()==v[j].getDay()){
//						if(v[i].getHour()>v[j].getHour())
//        			{
//        				swap(v[i], v[j]);
//					} else if(v[i].getHour()==v[j].getHour())
//					if(v[i].getMinute()>v[j].getMinute())
//        			{
//        				swap(v[i], v[j]);
//					} else if(v[i].getMinute()==v[j].getMinute())
//					{
//						if(v[i].getGia()>v[j].getGia())
//        			{
//        				swap(v[i], v[j]);
//					} 
//					}
//					}
//					}
//					
//					}
//				}
//			}
//		}
};


int main()
{   
    vector<VeMayBay> a;
    int luachon;
    while(true)
    {
    	
    	cout<<"\n\n\t\t NHAP THONG TIN CHUYEN BAY"<<endl;
    	cout<<"Nhap phim 1 de nhap"<<endl;
    	cout<<"Nhap phim 2 de ket thuc lenh nhap"<<endl;
    	cin>>luachon;
    	if(luachon==1)
    	{
    		VeMayBay x;
    		x.nhap();
    		a.push_back(x);
		} else if(luachon==2)
		{
			break;
		}
		 else
		 {
		 	cout<<"Lua chon khong hop le, xin nhap lai!!!";
		 }
	}
	KhachHang b;
     b.nhap() ;
     cout<<endl;
	int LuaChon;
	
	while(true)
	{   
	    cout<<"\n\n\t\t PHAN KHACH HANG"<<endl;
	    cout<<"Nhap 1 de xem thong tin cac chuyen bay"<<endl;
	    cout<<"Nhap 2 de mua giao dich"<<endl;
	    cout<<"Nhap 3 de ket thuc giao dich"<<endl;
		cin>>LuaChon;
        if(LuaChon==1)
        {
        for(int i=0; i<a.size(); i++)
        {
    	a[i].display(); 
	    }
		} else if(LuaChon==3)
		{
			break;
		} 
else if(LuaChon==2)
		{
			string  mavecanmua;
			cout<<"Nhap ma ve can mua: ";
			cin>>mavecanmua;
			int soluongcanmua;
		for(int j=0; j<a.size(); j++)
			{
				if(a[j].getmave() == mavecanmua)
				{
					a[j].display();
					cout<<"Nhap so luong ve can mua: ";
					cin>>soluongcanmua;
					if(a[j].getsoluong()-a[j].getsoluongdaban()<soluongcanmua)
					{
						cout<<"So luong ve con lai khong du"<<endl;
						cout<<"Xin thuc hien lai!"<<endl;
					} else 
					{
						cout<<"Quy khach can thanh toan: "<<soluongcanmua*a[j].getGia()<<"VND"<<endl;
						
						cout<<"Cam on quy khach da giao dich, hen gap lai!!!";
						
						b.display();
						cout<<endl;
						a[j].display();
						break;
						
					}
				}
				
	}
			
	}
		 else {
			cout<<"Quy khach nhap sai, xin nhap lai!"<<endl;
		}
		
	} 
	return 0;
}


