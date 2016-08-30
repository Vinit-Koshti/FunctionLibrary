#include<iostream>
#include<conio.h>
#include "randLibrary.h"
//int* randomGenerator(int* arr,int length)

using namespace std;

void merge(int* arr, int* fh, int fhsize, int* sh, int shsize);
void mergesort(int* arr, int size );


void mergesort(int* arr, int size )
{
    int mid=size/2;
    int fh[mid], fhsize=mid, sh[size-mid], shsize=size-mid;

    if(size>1)
    {

        for(int j=0,k=mid; j<mid, k<size; j++, k++)
        {
            fh[j]=arr[j];
            sh[k]=arr[k];
        }

    }
    mergesort(fh, fhsize);
    mergesort(sh, shsize);
    merge(arr, fh, fhsize, sh, shsize);

}

void merge(int* arr, int* fh, int fhsize, int* sh, int shsize)
{
    int p=0, q=0, r=0;

    while(p!=fhsize && q!=shsize)
    {
        if(fh[p]<sh[q])
        {
            arr[r]=fh[p];
            p++;
            r++;
        }
        else
        {
            arr[r]=sh[q];
            q++;
            r++;
        }
    }

    if(p==fhsize && q<shsize)
    {
        while(q<shsize)
        {
            arr[r]=sh[q];
            q++;
            r++;
        }
    }
    if(q==shsize && p<fhsize)
    {
        while(p<fhsize)
        {
            arr[r]=fh[p];
            p++;
            r++;
        }
    }
}

int main()
{
    cout<< "enter the number of number you want in array: ";
    int size;
    cin>>size;

    int arr[size];
    int* ptr = randomGenerator(arr,size);

    for(int i=0; i<size; i++)
    {
        arr[i]=*ptr;
        cout<< arr[i]<<"  ";
        ptr++;
    }

    mergesort(arr, size);
    cout<<endl;
    cout<<endl;
    cout<<"sorted array: "<<endl;

    for(int l=0; l<size; l++)
    {
        cout<<arr[l]<<"  ";
    }

}
