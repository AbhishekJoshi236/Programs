/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
class complex
{
    private:
        int a;
    
    public:
        void setdata(int x)
        {
            a=x;
        }
        
        void display()
        {
            cout<<"sum is "<<a;
        }
        
        complex operator+(complex c)        //Another way to write-  (1) complex add(complex c)
        {
            complex temp;
            temp.a=a+c.a;
            return(temp);
        }
};
int main()
{
    complex c1,c2,c3;
    c1.setdata(10);
    c2.setdata(5);
    c3=c1+c2;                               //Another way to write- (1) c3=c1.add(c2);                (2) c3=c1.operator+(c2);
    c3.display();
    return 0;
}
