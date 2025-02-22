#include <iostream>
using namespace std;

double getLength()
{   
    double length;
    cout<<"Enter the rectangle's length: ";
    cin>>length;
    return length;
}

double getWidth()
{
    double width;
    cout<<"Enter the rectangle's width: ";
    cin>>width;
    return width;   
}

double getArea(double length, double width )
{
    double area;
    area=length*width;
    return area;
}

void displayData(double length , double width , double area)
{   
    cout<<"Length: "<<length<<endl;
    cout<<"Width : "<<width<<endl;
    cout<<"Area  : "<<area<<endl;
}

int main()
{
    double width, length, area;
    length = getLength();
    width = getWidth();
    area = getArea(length, width);
    displayData(length, width, area);
}


