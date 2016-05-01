#include<iostream>
using namespace std;


int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);
int binarySearch2(int[], int, int, int);

int unimodalBinarySearch(int arr[],int n,int key)
{
    int pivot = findPivot(arr, 0, n-1);

    cout<<endl<<"Peak Index:"<<pivot<<endl;

    if (pivot == -1)
        return binarySearch(arr, 0, n-1, key);

    if (arr[pivot] == key)
        return pivot;


    int z = binarySearch(arr, 0, pivot-1, key);
    if(arr[z]==key)
        return z;

    z = binarySearch2(arr, pivot+1, n-1, key);
    if(arr[z]==key)
        return z;

}

int findPivot(int arr[], int low, int high)
{

    if (high < low)  return -1;
    if (high == low) return low;

    int mid = (low + high)/2;
    if (mid < high && arr[mid] > arr[mid + 1] && arr[mid]>arr[mid-1])
        return mid;

    if (arr[mid+1] < arr[mid] && arr[mid-1] > arr[mid])
        return findPivot(arr, low, mid-1);
    return findPivot(arr, mid + 1, high);
}


int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid -1), key);
}

int binarySearch2(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch2(arr, low, (mid -1), key);
    return binarySearch2(arr, (mid + 1), high, key);
}



int main()
{
    int arr[]= {1,3,5,6,8,9,7,4,2,0};
    cout<<"arr[]={1,3,5,6,8,9,7,4,2,0}"<<endl;
    cout<<"Enter the key: ";
    int key;
    cin>>key;
    cout<<"Key Index: "<<unimodalBinarySearch(arr, 10, key);
}
