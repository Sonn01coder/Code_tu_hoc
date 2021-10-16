#include <iostream>
#include <string>
#include <cmath>
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
		KhachHang();
		~KhachHang();
		KhachHang(string maKhachHang, string name, string add, int tel)
		{
			this->maKhachHang=maKhachHang;
			this->name=name;
			this->add=add;
			this->tel=tel;
		}
		void nhap()
		{
			cout<<"\n\n\t\t NHAP THONG TIN KHACH HANG ";
			cout<<"Nhap ma khach hang: ";
			cin>>maKhachHang;
			cout<<"Nhap ten khach hang: ";
			cin>>name;
			cout<<"Nhap dia chi khach hang: ";
			cin>>add;
			cout<<"Nhap so dien thoai lien he: ";
			cin>>tel;
		}
		
		void display()
		{
			cout<<"\n\n\t\t XUAT THONG TIN KHACH HANG ";
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
		Time();
		~Time();
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
		Date();
		~Date();
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
	    Ve();
		~Ve();
		Ve(Time time, Date date, string mave, int soluong, int soluongdaban, int gia)
		{
			this->time=time;
			this->date=date;
			this->mave=mave;
			this->soluong=soluong;
			this->soluongdaban=soluongdaban;
			this->gia=gia;
		}	
		
		void nhap()
		{
			cout<<"\n\t NHAP THOI GIAN BAY"<<endl;
			time.nhap();
			cout<<"\n\t NHAP THONG TIN NGAY BAY"<<endl;
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
};

class VeMayBay:public Ve
{
	private: 
	    string tenchuyen;
	    int mamaybay;
	public:
		VeMayBay();
		~VeMayBay();
		VeMayBay(Time time, Date date, string mave, int soluong, int soluongdaban, int gia, string tenchuyen,  int mamaybay):Ve(time, date, mave, soluong, soluongdaban, gia)
		{
		    this->tenchuyen=tenchuyen;
			this->mamaybay=mamaybay;
		}
		void nhap()
		{
			cout<<"\n\n\t\t NHAP THONG TIN VE MAY BAY";
			cout<<"Nhap ten chuyen bay: ";
			cin>>tenchuyen;
			Ve::nhap();
			cout<<"Nhap ma may bay: ";
			cin>>mamaybay;
			
			
		}
        
        void display()
        {
        	cout<<"\n\n\t\t THONG TIN VE MAY BAY";
        	cout<<"Ten chuyen bay: "<<tenchuyen<<endl;
        	cout<<"Ma may bay: "<<mamaybay<<endl;
			Ve::display();
			
		}

};


int main()
{   
   VeMayBay x;
   x.nhap();
   x.display();

	return 0;
}


