#include<stdio.h>
#include<stdlib.h>

void msort(int arr[] , int l , int r);
void merge(int arr[] , int p , int q, int r);

void msort(int arr[],int l , int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        
        msort(arr,l,m);
        msort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j,k;
    
    int L[n1] , R[n2];
    
    for(i=0;i<n1;i++)
    {
        L[i] = arr[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = arr[q+1+j];
    }
    i=j=0;
    k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int n,i;
    
    printf("enter the number:");
    scanf("%d",&n);
    
    int arr[n];
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("origianl array:");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("-----------");
    
    msort(arr,0,n-1);
    printf("origianl array:");
    for(i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }
    
}
