#include <stdio.h>


void merge(int *a, int start, int mid, int end)
{
    int temp[100];
    int i = start, j = mid+1, k=0;
    
    while(i <= mid && j <= end)
    {
        if a[i] < a[j]
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= end)
        temp[k++] = a[j++];
    
    for(k=start;k <= end ;k++)
        a[k] = temp[k];
}

void merge_sort_recusion(int *a, int start, int end)
{
    int mid = (start+end)/2;
    if(start >= end)
        return;
    
    merge_sort(a, start, mid);
    merge_sort(a, mid+1, end);
    merge(a, start, mid, end);
}

int main()
{
    int i =0, mid=0;
    int a[] = {12, 23, 45, 55, 66, 22, 10};
    int no = (sizeof(a)/sizeof(a[0]));
    mid = (0+no)/2;
    merge_sort_recursion(a, 0, no-1);
    for(i =0 ; i <= no -1;i++)
    printf("\n%d",a[i]);
    return 0;
}
