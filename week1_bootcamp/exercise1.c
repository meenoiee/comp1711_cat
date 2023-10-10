# include <stdio.h>

int main()
{
    float width;
    float height;
    printf("Enter the width of the rectengle : ");
    scanf("%f",&width);
    printf("Enter the height of the rectengle : ");
    scanf("%f",&height);

    float area = width * height;

    printf ("The area of the rectengle is : %f ", area);
}