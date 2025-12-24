#include<iostream>
#include<fstream>
#include <cmath>
using namespace std;
struct  sinhvien
{
    string masv;
    int somon;
    double diemtb;
    int hocphi;
};
void nhap(sinhvien sv[], int &n)
{
    for(int i =0 ; i < n ; i++)
    {
        cout<<"\nhap sinh vien thu "<<i+1;
        cout<<"nhap ma sinh vien : ";
        getline( cin , sv[i].masv);
        cout<<"\n nhap so mon hoc cua sinh vien : ";
        cin>> sv[i].somon;
        cout<<"\n nhap diem tb cua sinh vien : ";
        cin>> sv[i].diemtb;
        sv[i].hocphi = sv[i].somon * 350000;
        cin.ignore();
    }
}
double demtb(sinhvien sv[], int n )
{
    double smmax = sv[0].somon;
    for(int i =0 ; i < n ; i++)
    {
        if(sv[i].somon > smmax)
        {
            smmax = sv[i].somon;
        }
    }
    double tbmin = 0 ;
    for ( int i =0 ; i < n ; i++)
    {
        if (sv[i].somon== smmax)
        {
        
        if(tbmin == 0 || sv[i].diemtb < tbmin)
        {
            tbmin = sv[i].diemtb;
        }
    }

    }
    int dem =0 ; 
    for(int i =0 ; i < n ; i++)
    {
       
        if(sv[i].somon== smmax && sv[i].diemtb == tbmin)
        {
            dem++;
        }
    
    }
    return dem;

}
double hocphitb(sinhvien sv[], int n)
{
    double tbhp =0 ;
    for(int i = 0 ; i < n ; i++)
    {
        tbhp += sv[i].hocphi;
    }
    tbhp = tbhp /n;
    double svhp=0;
    int dem =0;
    for(int i =0 ; i < n ; i++)
    {
        if(sv[i].hocphi > tbhp )
        {
            svhp += sv[i].hocphi;
            dem++;
        }

    }
    if(dem!=0 ) return svhp / dem;
    return dem;
}
void ghitep(sinhvien sv[], int n )
{
    ofstream f("sm.txt");
    if(!f)
    {
        cout<<"\n khong ghi duoc tep .";
    }
    for(int i =0 ; i < n ; i++)
    {
        f<<sv[i].somon<<" ";
    }
    f.close();

}
bool sochinhphuong(int n)
{
    if(n < 0) return false;
    int k = sqrt(n);
    return k*k==n;
}
void docfile(sinhvien sv[], int n)
{
    ifstream f("sm.txt");
    if(!f)
    {
        cout<<"khong doc duoc  file .";
    }
    int x;
    bool checkchinhphuong = false;
    for(int i =0 ; i < n ; i++)
    {
        f>>x;
        if(sochinhphuong(x))
        {
            cout << x <<" ";
            checkchinhphuong = true;
        }
    }
    if(!checkchinhphuong)
    {
        cout<<"\n khong co so chinh phuong ";
    }
    f.close();
}


int  main()
{
    int n ;
    cout<<"nhap so sinh vien can nhap : ";
    cin>>n;
    cin.ignore();
    sinhvien sv[100];
    nhap(sv,n);
    int kq = demtb(sv,n);
    if(kq ==0 )
    {
        cout<<"\n khong co sinh vien nao so mon nhieu nhat ma diem thap nhat .";
    }
    else
    {
        cout<<"\n co "<<kq<<" sinh vien co so mon nhieu nhat ma so diem thap nhat .";
    }
    cout<<"\n hoc phi trung binh cua sv co hoc phi lon hon tb ."<<hocphitb(sv,n);
    
    ghitep(sv,n);
    docfile(sv,n);






    return 0;
}