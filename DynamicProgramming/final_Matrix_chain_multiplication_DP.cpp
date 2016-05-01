#include<iostream>
#include<conio.h>
using namespace std;
int func(int n , int d[],int **S)
{
    int i,j,k;
    int M[n][n];
    int minimum;
    int pos;
    for(i=0; i<n; i++)
    {
        M[i][i]=0;
    }
    int diagonal;
    for(diagonal=1; diagonal<=n-1; diagonal++)
    {
        for(i=0; i<=n-diagonal-1; i++)
        {
            j=i+diagonal;

            minimum = M[i][i] + M[i+1][j] + d[i]*d[i+1]*d[j+1];
            S[i][j] = i;
            for(k=i; k<=j-1; k++)
            {
                int temp;
                temp = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
                if(temp < minimum)
                {
                    minimum = temp;
                    pos = k;
                    S[i][j] = k;
                }
            }

            M[i][j] = minimum;
        }
    }
    return M[0][n-1];
}
void parenthesize(int **S , int low , int high)
{
    if(low == high)
    {
        cout<<"A"<<low+1;
    }
    else
    {
        cout<<"(";
        parenthesize(S,low,S[low][high]);
        parenthesize(S , S[low][high]+1 , high);
        cout<<")";
    }

}
int main()
{
    int n;
    cout << "Matrix entry Format: 20 2 30 12 <means three matrix like 20x2, 2x30, 30x12> ";
    cout << endl << "Enter the number of matrices:";
    cin >> n;
    int d[n+1];
    for(int i=0; i<=n; i++)
    {
        cout << endl << "Enter value here: ";
        cin >> d[i];
    }

    int **S = new int*[n];
    for (int i = 0; i < n; i++)
    {
        S[i] = new int[n];
    }
    cout<<"Minimum cost of multiplication : ";
    int z = func(n,d, S);
    cout<<z<<endl;
    cout<<endl;
    parenthesize(S,0,n-1);
    getch();
    return 0;
}
