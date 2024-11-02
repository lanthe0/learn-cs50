#include <stdio.h>
void merge(int a[],int left,int right,int n);
int main()
{
    int number[]={36,98,42,11,23,45,76,54,34};
    merge(number,0,7,8);
    for(int i=0;i<8;i++)
    printf("%d ",number[i]);
    return 0;
}


void merge(int a[],int left,int right,int n)
{
    if(n==1) return;
    else{
        int mid=(left+right)/2;
        merge(a,left,mid,n/2);
        merge(a,mid+1,right,n-n/2);//排序俩边
        int i=left,j=mid+1,k=0;
        int t[20];
        while(i<=mid&&j<=right)
        {
            if(a[i]<a[j]) t[k++]=a[i++];//小的放，并各进一位
            else t[k++]=a[j++];
        }
        while(i<=mid)
        {
            t[k++]=a[i++];
        }
        while(j<=right)
        {
            t[k++]=a[j++];
        }
        for(int i=0;i<n;i++)
        {
            a[left+i]=t[i];
        }
        return;
    }   
}