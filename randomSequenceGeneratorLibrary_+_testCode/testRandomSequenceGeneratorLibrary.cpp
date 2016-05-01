#include<iostream>
#include "randLibrary.h"
//Library used to generate random sequence
//int* randomGenerator(int* arr, int length);
using namespace std;
int main()
{
    int  length;
    srand(time(NULL));
    cout << "Enter the length of random sequence: " ;
    cin>>length;
    cout<<endl;
    int arr[length];
    int* ptr=randomGenerator(arr,length);

    cout <<"generated sequence: "<<endl;

    for(int z=0; z<length; z++)
    {
        cout << *(ptr+z) <<"  ";
        arr[z]=*(ptr+z);
    }

}
