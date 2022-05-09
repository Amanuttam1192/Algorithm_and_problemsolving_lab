#include <iostream>
#include<time.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
int largest = i; // Initialize largest as root
int l = 2 * i +1; // left = 2*i + 1
int r = 2 * i + 2; // right = 2*i + 2
if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;

if (largest != i) {
swap(arr[i], arr[largest]);

heapify(arr, n, largest);
}
}
void buildHeap(int arr[], int n)
{
for (int i = n/2; i >= 0; i--) {

heapify(arr, n, i);
}
cout << "Array representation of Heap is:\n";
for (int i = 0; i < n; ++i)
cout << arr[i] << " ";
cout << "\n";
}

int main()
{
int n;
clock_t start,end;
start = clock();
cout<<"enter no of terms";
cin>>n;
int arr[n];
cout<<"eneter the elements:";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
buildHeap(arr, n);
end = clock();
printf("\nThe time for the event was: %d",(end-start)/CLK_TCK);
return 0;
}
