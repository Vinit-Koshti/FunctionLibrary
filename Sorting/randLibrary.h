#include<stdlib.h>
#include<time.h>
int* randomGenerator(int* arr,int length);

int* randomGenerator(int* arr,int length)
{
    for(int j=0; j<length; j++)
    {
        arr[j]=j;
    }

    for(int i=length; i>0; i--)
    {
        int temp=rand()%length;
        arr[i]=temp;
        arr[temp]=i;
    }

    return arr;

}
