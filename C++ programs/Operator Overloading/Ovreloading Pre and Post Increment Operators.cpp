#include <iostream>
using namespace std;

class integer {
    private:
        int a;
    public:
        void setdata (int x)
        {       a=x;                 }
        void display()
        {       cout<<"  a is: "<<a;   }

    integer operator ++ ()                                          //Pre incrementing
    {
        integer temp;
        temp.a=++a;
        return (temp);
    }

    integer operator ++ (int)                                      //Post incrementing
    {
        integer temp;
        temp.a=a++;
        return(temp);

    }                          
};

int main()
{
    integer i1,i2;
    i1.setdata(5);
    i2=++i1;                                            //i2=i1.operator ++();
    cout<<"\nPRE INCREMENTING...\n";          
    i1.display();
    i2.display();
    cout<<"\nPOST INCREMENTIONG....\n";
    i2=i1++;                                            
    i1.display();
    i2.display();
    return 0;
}
