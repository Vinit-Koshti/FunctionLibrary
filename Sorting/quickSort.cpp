#include<iostream>
#include "randLibrary.h"
//int* randomGenerator(int* arr,int length)

using namespace std;
int arr[20];

int divide(int low, int high );
void sort(int low,int high );

void sort(int low,int high ) {
   int pivotLocation;
    if( low < high ) {
      pivotLocation = divide( low , high );
      sort( low, pivotLocation );
      sort ( pivotLocation+1, high );
    }
}

int divide(int low, int high ) {
    int mid=(low+high)/2;   // initial location of pivot
    // swap a[ mid ] and a[ low ]  // bring pivot to beginning
    int pivot=arr[low];     // save value of pivot
    int lastsmall=low;   // lastsmall points to end of 1 element list
    for(int j=low+1; j < high ; j++ ) {
       if(arr[j]<pivot) {
          lastsmall++;
          // swap a[ j ] and a[ lastsmall ]
       }
    }
    // swap a[low] and a[lastsmall] to put pivot in correct location
    return lastsmall;   // final location of pivot is returned
}



int main()
{
    cout<<"Enter the length of sequence: ";
    int size1, low=0;
    cin>> size1;

    int* ptr=randomGenerator( arr,size1);

    for(int d=0; d<size1; d++)
    {
        arr[d]=*ptr;
        cout<<arr[d]<<"  ";
        ptr++;
    }
    int  arr[size1];
    sort(low,size1);
    cout<< endl;
    for(int f=0; f<size1; f++)
    {
        cout<<arr[f]<<"  ";
    }

}
