#include<iostream>
using namespace std;

class number
{
    private:
        int a;
    public:
        void setdata (int x)
        {
           a=x;
        }
        void display()
        {
           cout<<"sum is:  "<<a;
        }

    friend  number operator +(number,number);
};

number operator +(number num1,number num2)
{
    number temp;
    temp.a=num1.a+num2.a;
    return (temp);
}


int main()
{
    number n1,n2,n3;
    n1.setdata(2);
    n2.setdata(8);
    n3=n1+n2;
    n3.display();

    return 0;   
}