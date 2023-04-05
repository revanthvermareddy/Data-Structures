#include<bits/stdc++.h>
using namespace std;

/*
sort(param1, param2): sort function takes 2 prams
pram1: address to start element
param2: next address of the address of end element

The name of this sorting algorithm is 'intro sort'
intro sort: its a combination of 3 sorting algorithms (quick sort, heap sort, insertion sort)
This is the best sorting algorithm

Starts with quick sort, and when the depth of recursion in quick sort become more
it will change to heap sort and when number of elements become small
then it changes to insertion sort

TC: O(nlogn)
*/

int main(){
	// with arrays
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	// with vectors
	int n2;
	cin>>n2;
	vector<int> v(n2);
	for(int i=0; i<n2; ++i){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n2; ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}