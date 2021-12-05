#include<iostream>
using namespace std;

class complex 
{
    private:
        int a,b;
        
    public:
        friend istream& operator>>(istream &input, complex &c);
        friend ostream& operator<<(ostream &output, complex c);
        
};

istream& operator>>(istream &input, complex &c)
{
    input>>c.a>>c.b;
    return(input);
}
ostream& operator<<(ostream &output, complex c)
{
    output<<"a: "<<c.a<<" b: "<<c.b;
    return (output);
}

int main()
{
    complex s;
    cout<<"Enter two numbers: ";
    cin>>s;
    cout<<"Entered numbers are: ";
    cout<<s;
    
    return 0;
}
