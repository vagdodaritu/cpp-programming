#include<iostream>
using namespace std;
class rectangle
{
    float length,width;
public:
    void getdata();
    float perimeter();
    float area();
};
void rectangle::getdata()
{
    cout<<"enter length : ";
    cin>>length;
    cout<<"enter width : ";
    cin>>width;
}
float rectangle::area()
{
    return length*width;
}
float rectangle::perimeter()
{
    return 2*(length+width);
}
int main()
{
    rectangle rec;
    int ch;
    n:
    cout<<"enter length and width:"<<endl;
    rec.getdata();
    cout<<"perimeter is : "<<rec.perimeter()<<endl;
    cout<<"area is : "<<rec.area()<<endl;
    cout<<"do you want to re-enter values or exit"<<endl<<"press 1 for re-enter values and press 0 for exit.";
    cin>>ch;
    if(ch==0)
    {
        return 0;
    }
    else if (ch==1)
    {
        goto n;
    }
    else
    {
        cout<<"enter a valid choice";
    }
    return 0;
}


