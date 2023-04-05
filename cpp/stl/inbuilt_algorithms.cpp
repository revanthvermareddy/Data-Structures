#include<bits/stdc++.h>
using namespace std;

int main() {
	// 1. For non-arrays
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i) cin>>v[i];

	int min = *min_element(v.begin()+3, v.end());
	cout<<min<<endl;
	int max = *max_element(v.begin(), v.end());
	cout<<max<<endl;
	int sum = accumulate(v.begin(), v.end(), 0);  // accumulate(v.begin(), v.end(), initial_sum);
	cout<<sum<<endl;
	int ct = count(v.begin(), v.end(), 5);  // count(v.begin(), v.end(), element_to_find_count);
	cout<<ct<<endl;
	auto it = find(v.begin(), v.end(), 25);
	if (it != v.end()) cout<<(*it)<<endl;
	else cout<<"Element not found"<<endl;
	reverse(v.begin()+3, v.end());  // inplace reverse, it can be used on vectors, arrays, strings etc
	for(auto val: v) cout<<val<<" ";
	cout<<endl;
	string s = "abcdsfdsjf";
	reverse(s.begin()+1, s.end());
	cout<<s<<endl;

	// TC: O(n), all of the above functions run a look till n elements to perform the required operation
	// count and find have TC: O(logn) when dealing with sets and maps and O(n) when dealing with arrays and vectors

	// 2. For arrays
	int n2;
	cin>>n2;
	int a[n2];
	for(int i=0; i<n2; ++i) cin>>a[i];
	int min2 = *min_element(a+3, a+n2);
	cout<<min2<<endl;
	int max2 = *max_element(a, a+n2);
	cout<<max2<<endl;
	int sum2 = accumulate(a, a+n2, 0);  // accumulate(v.begin(), v.end(), initial_sum);
	cout<<sum2<<endl;
	int ct2 = count(a, a+n2, 5);  // count(v.begin(), v.end(), element_to_find_count);
	cout<<ct2<<endl;
	auto *ptr = find(a, a+n2, 25);
	if (ptr != a+n) cout<<(*ptr)<<endl;
	else cout<<"Element not found"<<endl;
	reverse(a+3, a+n2);  // inplace reverse, it can be used on vectors, arrays, strings etc
	for(auto val: a) cout<<val<<" ";
	cout<<endl;
}