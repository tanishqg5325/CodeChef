#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i=left, j=mid, k=left;
    int inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int f(int a[], int n, int x)
{
    int b[n];
    for(int i=0;i<n;i++) b[i]=a[i]^x;
    return mergeSort(b,n);
}

int main()
{
    int t,n,k,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>p;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int r = pow(2,k);
        pair <int,int> pairs[r];
        for(int x=0;x<r;x++)
        {
            pairs[x].second=x;
            pairs[x].first=f(a,n,x);
        }
        sort(pairs,pairs+r);
        cout<<pairs[p-1].second<<endl;
    }
    return 0;
}
