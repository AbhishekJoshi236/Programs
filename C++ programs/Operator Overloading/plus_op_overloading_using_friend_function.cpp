#include<iostream>
using namespace std;

class complex 
{
    private:
        int a;
    public: 
        void setdata (int x)
        {       a=x;        }

        void display()
        {   cout<<"Sum is: "<<a;     }

        friend complex operator+(complex,complex);
};

complex operator+(complex c1,complex c2)
{
    complex temp;
    temp.a=c1.a+c2.a;
    return temp;
}

int main()
{
    complex c1,c2,c3;
    c1.setdata(10);
    c2.setdata(20);
    c3=c1+c2;
    c3.display();

    return 0;
}
