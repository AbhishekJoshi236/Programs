/*  ABHISHEK JOSHI */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1;

int preference (int c)
{ 
    if(c == ')')
        return 1;
    if(c=='+' || c=='-')
        return 2;
    if(c=='*' || c=='/')
        return 3;
}

int main()
{  
    char s[100],c[100];
    int i=0,t=0;
    printf("Enter INFIX expression: ");
    scanf("%s",s);
    
    int d=strlen(s)-1;
    for(int j=0;j!=d;d--,j++)
    { 
        char b=s[d];
        s[d]=s[j];
        s[j]=b;
    }
    
    printf("Showing its POSTFIX expression: ");
    while(s[i]!='\0')
    {
        if(isalpha(s[i]) )
        {  
            c[t]=s[i];
            t++;
        }
        else if(s[i]==')')
        {  
            ++top;
            stack[top]=s[i];
        }
        else if(s[i]=='(')
        { 
            while(stack[top]!=')')
            { 
                c[t]=stack[top];
                t++;
                --top;
            }
        --top;
        }
        else
        { 
            while( preference(s[i]) <= preference(stack[top]) )
            { 
                c[t]=stack[top];
                --top;
                 t++;
            }
            top++;
            stack[top]=s[i];
        }
        
        i++;
  }
    while(top != -1)
    { 
        c[t]=stack[top];
        --top;
        t++;
    }
    
    for(int j=0,d=t-1;j!=d;d--,j++)
    {
        char b=c[d];
        c[d]=c[j];
        c[j]=b;
    }
    
   for(int j=0;j<t;j++)
      printf("%c",c[j]);
      
  return 0;
}