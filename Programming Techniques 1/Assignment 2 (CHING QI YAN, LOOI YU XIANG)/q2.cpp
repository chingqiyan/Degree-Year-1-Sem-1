#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void input(int item[],int price[],int discount[], int SIZE){
	ifstream infile;
	infile.open("input.txt");
	if (!input){
	cout << "ERROR: Cannot open file\n";
	exit(1);
	}
	
	for (int count=0; count < SIZE; count++)
   {
	   infile >> item[count] >> price[count]>> discount[count];
   }
   infile.close();
}

double output(int item[],int price[],int discount[], int SIZE, double AfterDiscount[]){
	for(int count=0; count<SIZE; count++){
		AfterDiscount[count] = price[count]*(static_cast<double>(1-discount[count]*0.01));
	}
	
	cout<<"Number of items on sale"<<endl<<endl<<"--------------------------------------------------------\n"<<endl;
	cout<<setw(10)<<"Item No"<<setw(10)<<"Price"<<"   "<<"Discount(%)"<<"  "<<"Price after discount\n"<<endl;
	for(int count=0; count<SIZE; count++){
		cout<<setw(10)<<right<<item[count]<<setw(10)<<right<<price[count]<<setw(10)<<right<<discount[count]<<setw(15)<<right<<AfterDiscount[count]<<endl;
	}
}

int main(){
	const int SIZE = 10;
	int item[SIZE];
	int price[SIZE];
	int discount[SIZE];
	double AfterDiscount[SIZE];
	
	input(item, price, discount, SIZE);
	output(item, price, discount, SIZE, AfterDiscount);
}


