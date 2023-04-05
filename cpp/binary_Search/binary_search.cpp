#include<bits/stdc++.h>
using namespace std;

/*
Binary search can be applied on any monotonous function
even predicate functions (FFFFTTTT or TTTTFFFF) which are monotonous can be used with binary search
*/

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	int to_find;
	cin>>to_find;

	// Binay Search
	int lo=0, hi=n-1;
	int mid;
	while(hi-lo>1){
		mid = (hi+lo)/2;
		if(v[mid] < to_find){
			lo = mid +1;
		}else{
			hi = mid;
		}
	}
	// TC: O(logn to the base 2)
	if(v[lo]==to_find)
		cout<<lo<<endl;
	else if(v[hi]==to_find)
		cout<<hi<<endl;
	else
		cout<<"Not Found"<<endl;
}