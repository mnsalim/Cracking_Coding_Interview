#include<stdio.h>

int sum_of_natural_numbers (int n)
{
    int sum = 0;

    for (int i=0; i<=n; i++)
    {
        sum = sum + i;
    }

    return sum;
}

int main()
{
    int inp;
    scanf("%d", &inp);

    printf("%d", sum_of_natural_numbers(inp));

    return 0;
}



