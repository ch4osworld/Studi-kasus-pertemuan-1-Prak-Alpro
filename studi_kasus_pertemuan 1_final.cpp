#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
main()
{
	string p[100];
	float m,x,y,h[100],total,bayar;
	float a,jumlahbayar;
	cout<<"Menu"<<endl;
	cout<<"a.ayam goreng RP.17.000"<<endl;
	cout<<"b.ayam bakar RP.21.000"<<endl<<endl;
	cout<<"memesan berapa menu : ";cin>>m;
	cin.ignore();
	for(int i=0; i<m;i++)
	{
		cout<<"pilihan "<<i+1<<" : ";getline(cin,p[i]);
		cout<<"harga : ";cin>>h[i];
		total+=h[i];	
		cin.ignore();	
	}
	if(total> 45000)
	{
		y=total*10/100;
		jumlahbayar=total-y;
		cout<<"jumlah uang yang harus di bayar = "<<jumlahbayar<<endl;
		cout<<"Bayar        : Rp.";cin>>bayar;
	}
	else if(total<=45000)
	{
		jumlahbayar=total;
		cout<<"jumlah uang yang harus di bayar = "<<jumlahbayar<<endl;
		cout<<"Bayar        : Rp.";cin>>bayar;
	}
		
	ofstream mengisi;
	mengisi.open("struk_alpro.txt",ios::app);
	mengisi<<endl;
	mengisi<<"STRUK BELANJA "<<endl;
	mengisi<<"---------------------------------------------------------"<<endl;
	mengisi<<"No   menu     Harga"<<endl;
	for (int i=0;i<m;i++){
		mengisi<<i+1<<setw(8)<<p[i]<<setw(10)<<h[i]<<endl; 
	}
	mengisi<<"---------------------------------------------------------"<<endl;
	
	mengisi<<"Total Harga  : Rp."<<jumlahbayar<<endl;
	mengisi<<"Bayar        : Rp."<<bayar<<endl;
	a=bayar-jumlahbayar;
	mengisi<<"Kembalian    : Rp."<<a<<endl; 
	mengisi.close();
	
	string layar;
	ifstream menampilkan("struk_alpro.txt");
			
	if(menampilkan.is_open())
	{
		while(getline(menampilkan,layar))
			cout<<layar<<endl;
		menampilkan.close();
	}
	else
		cout<<"fail"<<endl;
}
