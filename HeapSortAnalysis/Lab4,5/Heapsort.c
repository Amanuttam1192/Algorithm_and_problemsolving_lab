#include<stdio.h>

void swapArr(int A[100], int n, int m)
{
    int temp = A[n];
    A[n] = A[m];
    A[m] = temp;
}

void heapify(int A[100], int n, int i)
{
    int left = 2*i + 1, right = 2*i + 2;
    int large = i;
    
    if(left < n && A[left] > A[large])    large = left;
    if(right < n && A[right] > A[large])  large = right;

    if(large != i)
    {
        swapArr(A, i, large);
        heapify(A, n, large);
    }
}

void makeHeap(int A[100], int n)
{
    int i;
    for( i = (n-1)/2; i>=0; i++ )
    {
        heapify(A, n, i);
    }
}

void deleteMax(int A[100], int n)
{
    int x = A[0];
    swapArr(A, 0, n-1);
    n = n-1;
    heapify(A, n, 0);
}

void HeapSort(int A[100], int n)
{
    makeHeap(A, n);
    int i = 0;
    for(i = 0; i < n; i++)
        deleteMax(A, n);
}

int main()
{
    int A[] = {5, 11, 9, 10, 3, 6};
    int n = 6;
    HeapSort(A, n);
    int i = 0;
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    return 0;
}
