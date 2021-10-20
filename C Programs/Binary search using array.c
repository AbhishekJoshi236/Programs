#include <stdio.h>
int main()
{
    int n,item;
    printf("Enter size of array: ");
    scanf("%d",&n);
    
    int f=0,e=n-1;
    int a[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    printf("Enter searching element: ");
    scanf("%d",&item);
    
    int mid=f+(e-f)/2;
    while(f<=e)
    {
        if(item==a[mid])
        {
            printf("ITem found at %dth index.\n",mid);
            return 0;
        }
        else if(item<a[mid])
            e=mid-1;
        else
            f=mid+1;
    }
    printf("Item not found.\n");
    
    return 0;
}
