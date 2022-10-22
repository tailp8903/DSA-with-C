#include<stdio.h>

int BST(int low, int high, int A[], int key){
	if (low <= high){
		int mid = (low + high) / 2;
		if (A[mid] == key) return mid;
		else if (key < A[mid]) return BST(low, mid - 1, A, key);
		else return BST(mid + 1, high, A, key);
	}
	else return -1;
}

int main(){
	return 0;
}