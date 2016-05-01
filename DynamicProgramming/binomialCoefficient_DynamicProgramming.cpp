#include<iostream>
#include<conio.h>
using namespace std;

//return minimum of a and b
int  minimum(int  a , int  b)
{
    return a<=b?a:b;
}

int  Binomial_Coefficient(int  n , int  k)
{
    int  C[n+1][k+1];//matrix stores the previous results
    int  i, j, temp;
    for(i=0; i<=n; i++)
    {
        temp = minimum(i,k);
        for(j=0; j<=temp; j++)
        {
            if(j==0 || j==i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];//Pascal's Triangle logic
        }
    }
    return C[n][k];
}

int main()
{
    int  n, k, z, request=1;

    while(request)
    {
        cout<<"Enter the value of n and k :";
        cin>>n;
        cin>>k;
        cout<<endl;
        if (n>0 && k<=n && k>=0)//For error handling
        {
            z =  Binomial_Coefficient(n,k);
            cout<<"Value of coefficient is :" << z;
        }
        else
            cout << "NOTE: Negative numbers are not allowed and  k <= n, n>0, k>=0.";

        cout << endl;
        cout << "if want to continue enter 1 else 0:";
        cin >> request;
    }

    getch();
    return 0;
}
