#include<bits/stdc++.h>
using namespace std;

// sum of array definition
// sum(n, a) -> sum of elements uptil element of index n
// sum(n, a) = a[n] + sum(n-1, a)

int sum(int n, int a[]){
	if(n<0) return 0;
	return a[n] + sum(n-1, a);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	cout<<sum(n, a);
	// TC: O(n)
}
