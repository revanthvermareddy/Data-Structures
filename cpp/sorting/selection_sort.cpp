#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];

	for(int i=0; i<n; ++i){
		cin>>a[i];
	}

	/* SELECTION SORT: O(n^2) */
	for(int i=0; i<n; ++i){
		// selecting the minimum element index
		int minIndex = i;
		for(int j=i+1; j<n; ++j){
			if (a[j]<a[minIndex]) minIndex=j;
		}
		// SWAP the index element with the minimum element index
		swap(a[i], a[minIndex]);
	}

	for(int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	// TC: O(n^2)
}  