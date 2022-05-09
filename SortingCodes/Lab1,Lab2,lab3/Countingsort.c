#include <stdio.h>
#include <stdlib.h>
void counting_sort(int [], int);
int find_max(int [], int);
void print_array(int [], int);

int main(){
	puts("-----Counting Sort by Aman_1109-----");
	int a[] = {0,5,4,2,5,0,0,1,2,2,1,3,3,5};
	int length = sizeof(a) / sizeof(int);
	
	printf("Unsorted: ");
	print_array(a, length);
	counting_sort(a, length);
	
	printf("Sorted: ");
	print_array(a, length);
	
	return EXIT_SUCCESS;
}
void counting_sort(int a[], int length){
	
	int i, max = find_max(a, length);
	int c[max+1];
	
	for(i = 0; i < max + 1; c[i++] = 0); 
	
	for(i = 0; i < length; i++) c[a[i]]++;
	
	for(i = 1; i < max + 1; i++) c[i] = c[i - 1] + c[i];
	
	
	int b[length]; 
	int j = length - 1;
	for(i = 0; i < length; i++) {
		b[--c[a[j]]] = a[j];
		j--;
	}	
	
	
	for(i = 0; i < length; i++)	a[i] = b[i];

}
int find_max(int a[], int length){
	int i, max = a[0];
	for(i = 1; i < length; i++) {
		if(max < a[i]) max = a[i];
	}
	return max;
}
void print_array(int a[], int length){
	int i = 0;
	putchar('[');
	do {
		if(i > 0) printf(", ");
		printf("%d", a[i]);
	} while(++i < length);
	puts("]");
}
