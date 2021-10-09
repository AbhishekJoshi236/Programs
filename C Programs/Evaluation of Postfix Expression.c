
#include <stdio.h>

int stack[100];
int top=-1;

void push (char n)
{
    stack[++top]=n-48;
}

int main()
{
    char s[100];
    int i=0,sol=0;
    printf("Enter a POSTFIX Expression: ");
    scanf("%s",s);
    
    while(s[i]!='\0')
    {
        if(s[i]>='0' && s[i]<='9')
            push(s[i]);
        
        else
        {
            int b=stack[top];
            --top;
            
            int a=stack[top];
            --top;
            
            if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/')
            {
                if(s[i]=='+')
                    sol=a+b;
                else if(s[i]=='-')
                    sol=a-b;
                else if(s[i]=='*')
                    sol=a*b;
                else
                    sol=a/b;
                
                stack[++top]=sol;
            }
            
        }
        
        i++;
    }
    
    printf("Its evaluation is: %d\n",stack[top]);
    return 0;
}
