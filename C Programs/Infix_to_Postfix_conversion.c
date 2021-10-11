#include<stdio.h>
char stack[100];
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
int main()
{
    char s[100];
    int i=0;
    printf("Enter INFIX expression: ");
    scanf("%s",s);
    
    printf("Showing its POSTFIX expression: ");
    while(s[i]!='\0')
    {
        if( (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || (s[i]>='1'&&s[i]<='9') )
            printf("%c ",s[i]);
            
        else if(s[i]=='(')
        {
            ++top;
            stack[top]=s[i];
        }
        
        else if(s[i]==')')
        {
            while(stack[top]!='(')
            {
                printf("%c ",stack[top]);
                --top;
            }
            --top;
        }
        
        else
        {
            while( preference(s[i]) <= preference(stack[top]) )
            {
                printf("%c ",stack[top]);
                --top;
            }
            top++;
            stack[top]=s[i];
        }
        
        i++;
    }
    
    while(top != -1)
    {
        printf("%c ",stack[top]);
        --top;
    }
    return 0;
}
