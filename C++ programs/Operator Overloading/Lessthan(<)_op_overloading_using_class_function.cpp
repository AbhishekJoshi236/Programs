
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
            cout<<a<<" is smallest.\n";
        }
        
        int operator<(complex c)        
        {
            if(a<(c.a))
                return 1;
            else
                return 0;
        }
};
int main()
{
    complex c1,c2,c3;
    c1.setdata(10);
    c2.setdata(5);
    if(c1<c2)
        c1.display();
    else
        c2.display();
    return 0;
}
