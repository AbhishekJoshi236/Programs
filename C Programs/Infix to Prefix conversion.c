/* ABHISHEK JOSHI  */

#include<stdio.h>
#include<string.h>

char a[100];
int top=-1;

int preference (int c)
{
    if(c == '(')
        return 1;
    if(c=='+' || c=='-')
        return 2;
    if(c=='*' || c=='/')
        return 3;
}

void reverse(char s[],int d)
{ 
    for(int j=0;j!=d;j++,d--)
    {
        char b=s[d];
        s[d]=s[j];
        s[j]=b;
    }
}

int main()
{
    char s[100],c[100];
    int e,t=0;
    
    printf("Enter INFIX expression: ");
    scanf("%s",s);
    e=strlen(s);
    
    for(int j=0;j<e;j++)
    {
        if(s[j]==')')
            s[j]='(';
        else if(s[j]=='(')
            s[j]=')';
    }
    
    reverse(s,e-1);
    printf("Showig its PREFIX expression:  ");
    
    for(int i=0;s[i]!='\0';i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') )
        {
            c[t]=s[i];
            t++;  
        }
        
        else if(s[i]=='(')
        {
            ++top;
            a[top]=s[i];
        }
        
        else if(s[i]==')')
        {
            while(a[top]!='(')
            {
                c[t]=a[top];
                t++;
                --top;
            }
        --top;
        }
        
        else
        {
            while(preference(s[i]) <= preference(a[top]) )
            {
                c[t]=a[top];
                --top;
                t++;
            }
            
            top++;
            a[top]=s[i];
        }
    }
 
while(top != -1)
{
    c[t]=a[top];
    --top;
    t++;
}

reverse(c,t-1);

for(int j=0;j<t;j++)
     printf("%c",c[j]);
     
  return 0;
}
