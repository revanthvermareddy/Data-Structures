#include<bits/stdc++.h>
using namespace std;

/*

For upper_bound and lower_bound the pre-requisite is 
the array (in general the data structure) should be sorted

lower_bound(start_addr, end_addr, element): returns the location of the same element if it exists else the next higher element location that the given element
upper_bound(start_addr, end_addr, element): returns the location of next higher element that the given element

if the element is not present it then returns the last address or end_addr

so in case of arrays they return pointer
and in case of vectors they return iterator

TC: O(logn), where n = array size

In case of arrays and vectors: the algorithm uses binary search to do the operation in O(logn) time
In case of sets and maps: the algorithm uses tree traversals to do the operation in O(logn) time

*/

int main(){

	// 1. using arrays
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

	int *ptr = lower_bound(a, a+n, 6);
	if (ptr == (a+n)) {
		cout<<"Not Found";
		return 0;
	}
	cout<<(*ptr)<<endl;

	int *ptr2 = upper_bound(a+4, a+n, 5);
	if (ptr2 == (a+n)) {
		cout<<"Not Found";
		return 0;
	}
	cout<<(*ptr2)<<endl;

	// 2. using vectors
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
	
	auto it = upper_bound(v.begin(), v.end(), 4);
	if (it == v.end()) {
		cout<<"Not Found";
		return 0;
	}
	cout<<(*it)<<endl;

	auto it2 = upper_bound(v.begin(), v.end(), 6);
	if (it2 == v.end()) {
		cout<<"Not Found";
		return 0;
	}
	cout<<(*it2)<<endl;


	// 2. using sets or maps (we need not sort as by default they are already sorted)
	// Note: Beware, TLE error's can come when we use the regular syntax of upper_bound or lower_bound so we should use alternative syntax
	
	set<int> s;
	for(int i=0; i<(int)(1e6); ++i){  // TC: O(1e6*logn) < 1 sec
		s.insert(rand());  // TC: O(logn)
	}
	/*
	// This piece of code doesn't work

	for(int i=0; i<(int)(1e5); i++){
		auto it3 = lower_bound(s.begin(), s.end(), 4);  // this is O(n) operation
	}
	
	// TC: O(1e5*1e6) = 1e11 > 1 sec => TLE and exits with code 124
	*/
	
	for(int i=0; i<(int)(1e5); i++){
		auto it3 = s.lower_bound(4);  // this is O(logn) operation
	}
	// The above code works as the TC: O(nlogn) < 1 sec
}