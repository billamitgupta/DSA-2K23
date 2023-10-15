
#include <iostream>

using namespace std;

void selectionSort(int data[] , int size)
{
    int i,j, min,temp;
    for(int i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(data[j]<data[min])
            min=j;
        }
        temp=data[min];
        data[min]=data[i];
        data[i]=temp;
    }
}
int main()
{
    int n;
    cin>>n;
    int A[100];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    selectionSort( A, n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
