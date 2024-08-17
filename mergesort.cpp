#include<iostream>
using namespace std;
void merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    int lenleft=mid-s+1;
    int lenright=e-mid;
    int *left=new int[lenleft];
    int *right=new int[lenright];
    int k=s;
    for(int i=0;i<lenleft;i++)
    {
        left[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<lenright;i++)
    {
        right[i]=arr[k];
        k++;
    }
    int leftindex=0;
    int rightindex=0;
    int mainarrayindex=s;
    while(leftindex<lenleft && rightindex<lenright)
    {
        if(left[leftindex]<right[rightindex])
        {
            arr[mainarrayindex]=left[leftindex];
            mainarrayindex++;
            leftindex++;
        }
        else
        {
            arr[mainarrayindex]=right[rightindex];
            mainarrayindex++;
            rightindex++;
        }
    }
    while(rightindex<lenright)
    {
        arr[mainarrayindex]=right[rightindex];
        mainarrayindex++;
        rightindex++;
    }
    while(leftindex<lenleft)
    {
        arr[mainarrayindex]=left[leftindex];
        mainarrayindex++;
        leftindex++;
    }
    delete[] left;
    delete[] right;
}
void mergesort(int arr[],int s,int e)
{
    
    if(s>e)
    {
        return;
    }
    if(s==e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int arr[]={40,30,15,10,80,35};
    int size=6;
    int s=0;
    int e=size-1;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,s,e);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}