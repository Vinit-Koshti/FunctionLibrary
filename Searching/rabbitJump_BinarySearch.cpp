#include<iostream>
#include<math.h>
#include "randLibrary.h"
//int* randomGenerator(int* arr,int length);
using namespace std;

int binarySearch(int low, int high, int* arr,int key)
{
    int mid= (low+high)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return binarySearch(0,mid,arr,key);
    else
        return binarySearch(mid,high,arr,key);
}

int main()
{
    long N;
    int  n, key;
    cout<<"Enter the value of N: ";
    cin>>N;
    int directory[N];
    std::fill(directory,directory + N,1000 );

    cout<<"Enter the value of n: ";
    cin>>n;

    srand(time(NULL));
    int temp[n],j=0;
    int *ptr=randomGenerator(temp,n);
    for(int i=0; i<n; i++)
    {
        directory[i]=*ptr;
        ptr++;
    }
    for(int i=0; i<N; i++)
    {
        cout<<directory[i]<<" ";
    }
    while(directory[j]!=1000)
    {
        j=pow(2,j++);
    }
    cout<<endl;
    cout<<"Enter the number you want to find:";
    cin>>key;

    int k=binarySearch(0,j,directory,key);
    cout<<endl<<directory[k]<<" at position "<<k+1;

    return 0;
}
