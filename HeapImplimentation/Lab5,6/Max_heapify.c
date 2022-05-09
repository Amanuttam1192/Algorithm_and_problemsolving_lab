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
