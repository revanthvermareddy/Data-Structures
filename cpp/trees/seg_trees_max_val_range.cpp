/*
Segment Tree: https://www.youtube.com/watch?v=-dUiRtJ8ot0
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];
int seg[4*N];  // Max index of a segment tree is 4*N

void build(int ind, int low, int high){
	if(low==high){  // base case
		seg[ind] = a[low];
		return;
	}
	int mid = (low+high)/2;
	build(2*ind+1, low, mid);    // recursively go down to the left sub-tree
	build(2*ind+2, mid+1, high); // recursively go down to the right sub-tree
	seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);  // write logic based on requirement
}

int query(int ind, int low, int high, int l, int r){
	if(low>=l && high<=r) return seg[ind];  // BaseCase-1.If the node range(low, high) is completely within the query range(l,r)
	if(high<l || low>r) return INT_MIN;     // BaseCase-2.If the node range(low, high) is completely outside the query range(l,r)
	int mid = (low+high)/2;
	int left  = query(2*ind+1, low, mid, l, r);
	int right = query(2*ind+2, mid+1, high, l, r);
	return max(left, right);  // write logic based on requirement
}

int main(){
	// Step-1: Take user input into an array
	int n;
	cin>>n;
	for(int i=0; i<n; ++i) cin>>a[i];

	// Step-2: Build the segment tree using the input arrays as required
	build(0, 0, n-1);

	// Step-3: Query the range to display output
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(0, 0, n-1, l, r)<<endl;
	}
}