# include <stdio.h>

int main()
{
    int a[10];
    int count;

    for(count=0; count<10; count++)
    {
        a[count] = count * 10 + count;
    }

    printf("The first two components of the arrays are %d and %d",a[0],a[1]);
}    