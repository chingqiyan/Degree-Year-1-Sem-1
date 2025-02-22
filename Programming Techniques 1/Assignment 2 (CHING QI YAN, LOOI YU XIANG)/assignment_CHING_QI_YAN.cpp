#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <iomanip>

void Input(int item_num[], double price[], double discount[],int max_size, int& file_size)
{
    fstream input("input.txt",ios::in);

    if(input.fail())
    {
        cout<<"Error";
        exit(1);
    }
    while(file_size<max_size && input>>item_num[file_size]>>price[file_size]>>discount[file_size])
    {  
        ++file_size;
    }
    input.close();
}

void Output(int item_num[],double price[], double discount[], double price_disc[], int& file_size)
{
    for(int i=0;i<file_size;++i)
    {
        price_disc[i]=price[i]*((100-discount[i])/100);
    }
    cout<<"Number of items on sale\n"<<endl;
    cout<<"---------------------------------\n";
    cout<<setw(10)<<"Item No"<<setw(10)<<"Price"<<setw(10)<<"Discount(%)"<<setw(15)<<"Price after discount"<<"\n"<<endl;
    for(int i=0;i<file_size;i++)
    {
        cout<<setw(10)<<item_num[i]<<setw(10)<<price[i]<<setw(10)<<discount[i]<<setw(15)<<price_disc[i]<<endl;
    }
}

int main()
{
    const int SIZE=100;
    int item_num[SIZE],file_size=0;
    double price[SIZE], discount[SIZE], price_disc[SIZE];
    Input(item_num, price, discount, SIZE,file_size);
    Output(item_num, price, discount, price_disc,file_size);

}