#include <stdio.h>

int main()
{
    int num;
    printf("Please enter any integer : ");
    scanf("%d",&num);

    if(num%2==1)
    {
        printf("This integer is an odd number");clear

    }

    else
    {
        printf("This integer is an even number");
    }

    return 0;
}