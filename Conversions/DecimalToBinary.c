#include<stdio.h>
#include<conio.h>

int TenPower(int Index)
{
    int Num=1,i;
    if(Index==0)
        return 1;

    for(i=1; i<=Index; i++)
    {
        Num*=10;
    }

    return Num;
}

int main()
{
    int Q,i,Binary,R=0;
    printf("Enter a decimal number: ");
    scanf("%d",&Q);

    for(i=0; Q!=0; i++)
    {
        R+=(Q%2)*TenPower(i);
        Q=Q/2;
    }

    printf("%d",R);

    getch();
    return 0;
}
