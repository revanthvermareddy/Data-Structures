#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

// merge function
void merge(int l, int r, int mid){

	// n = 10
	// indexes = 0 1 2 3 4 5 6 7 8 9
	// l = 0, r = 9, mid = 4

	int l_sz = mid-l+1;
	int r_sz = r-mid;  // r-(mid+1)+1

	// create 2 arrays (L and R) with one additional size to store the INT_MAX
	int L[l_sz+1];
	int R[r_sz+1];

	// copy values of a[] from [l,l_sz-1] to L array 
	for(int i=0; i<l_sz; ++i){  // TC: O(n)
		L[i] = a[l+i];
	}

	// copy values of a[] from [mid+1,r_sz-1] to R array 
	for(int i=0; i<r_sz; ++i){  // TC: O(n)
		R[i] = a[mid+1+i];
	}

	// IMP: To prevent extra while loops that we may have to write if any one of L, R arrays gets exhausted first
	L[l_sz] = R[r_sz] = INT_MAX;

	// merge logic
	int l_i = 0;
	int r_i = 0;
	for(int i=l; i<=r; ++i){
		if(L[l_i] <= R[r_i]){
			a[i] = L[l_i];
			l_i++;
		} else {
			a[i] = R[r_i];
			r_i++;
		}
	}
}

// recursive merge sort function
void mergeSort(int l, int r){
	if (l==r) return;
	int mid = (l+r)/2;
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	// merge 2 sorted array's in O(n) using merge function
	merge(l, r, mid); // TC: O(n)
}

int main(){
	int n;
	cin>>n;

	// take array input to global array
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	
	// apply merge sort
	mergeSort(0, n-1);

	// print the merged array
	for(int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}

	// TC:
	// 1. total steps is equal to the num of possible times that n can be divided by 2 -> logn
	// 2. and in each step we do a merge of an array of length n -> n
	// Overall TC: O(nlogn)
}  