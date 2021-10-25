/* ABHISHEK JOSHI */
#include <stdio.h>
void toh(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("moving disk 1 from %c to %c.\n",a,b);
        return ;
    }
    
    toh(n-1,a,c,b);
    printf("moving disk %d from %c to %c.\n",n,a,b);
    toh(n-1,c,b,a);
}

int main()
{
    int n=3;
    char a='A',b='B',c='C';
    toh(n,a,b,c);

    return 0;
}
