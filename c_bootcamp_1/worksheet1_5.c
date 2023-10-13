#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Enter integer a : ");
    scanf ("%d",&a);

    printf("Enter integer b: ");
    scanf ("%d",&b);

    int t=b;
    b=a;
    a=t;

    printf("a : %d\nb : %d\n",a,b);

    

    
}