#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Helper function for printing array
 * 
 * @param A int type array
 * @param n int type size of array
 */
void print_array(int A[],int n);
/**
 * @brief Helper function for swapping
 * 
 * @param A int type array
 * @param i int type index i
 * @param j int type index j
 */
void swap_el(int A,int i,int j);
/**
 * @brief Helper function for finding parent of given index
 * 
 * @param i int type index
 * @return int parent of given index
 */
int node_parent(int i);
/**
 * @brief Helper function for finding left children of given index
 * 
 * @param i int type index
 * @return int left children of given index
 */
int node_left(int i);
/**
 * @brief Helper function for finding right children of given index
 * 
 * @param i int type index
 * @return int right children of given index
 */
int node_right(int i);
/**
 * @brief Max Heapify Algorithm for preserving max heap propery
 * 
 * @param A int type array
 * @param n int type size of array
 * @param i current node of heap
 */
void MAX_HEAPIFY(int A[],int n,int i);
/**
 * @brief Buld Max Heap Algorithm for building max heap
 * 
 * @param A int type array
 * @param n int type size of array
 */
void BUILD_MAX_HEAP(int A[],int n);
/**
 * @brief Main Heapsort Algorithm for sorting array
 * First we will build the max-heap using heapify algorithm at the same time
 * preserving the max-heap propery  
 * 
 * @param A int type array
 * @param n int type size of array
 */
void HEAPSORT(int A[],int n);

int main(int argc, char const *argv[])
{
    int A[10] = {14,16,10,7,8,3,9,2,1,4};
    int n = sizeof(A) / sizeof(A[0]);
    print_array(A,n);
    HEAPSORT(A,n);
    print_array(A,n);
    return 0;
}

void print_array(int A[],int n){
    for(int i=0;i < n;i++){
        cout<<A[i]<<" ";
        if(i+1 == n){
            cout<<endl;
        }
    }
}

void swap_el(int A[],int i,int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int node_parent(int i){
    return floor(i/2);
}
int node_left(int i){
    return 2*i + 1;
}
int node_right(int i){
    return 2*i + 2;
}

void MAX_HEAPIFY(int A[],int n,int i){
    int largest = i;
    int l = node_left(i);
    int r = node_right(i);
    if (l < n && A[l] > A[largest]){
        largest = l;
    }
    if (r < n && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        swap_el(A,i,largest);
        MAX_HEAPIFY(A,n,largest);
    }
}

void BUILD_MAX_HEAP(int A[],int n){
    for(int i = floor(n/2) - 1; i >= 0;i--){
        MAX_HEAPIFY(A,n,i);
    }
}

void HEAPSORT(int A[],int n){
    cout<<"Start building Max Heap."<<endl;
    BUILD_MAX_HEAP(A,n);
    cout<<"Max Heap has been built."<<endl;
    print_array(A,n);
    cout<<"Start sorting based on Heap."<<endl;
    for(int i = n - 1; i >= 0;i--){
        swap_el(A,i,0);
        MAX_HEAPIFY(A,i,0);
    }
}
