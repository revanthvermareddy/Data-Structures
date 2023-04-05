#include<bits/stdc++.h>
using namespace std;

// comarator function for decreasing order of sort
bool cmp(int a, int b){
	return a>b;
}

// custom comarator function for pair of integer comparision as required
bool cmp_pairs(pair<int,int> a, pair<int,int> b){
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main(){
	/*
	Custom comparator for an array of integers
	*/
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	sort(a, a+n, cmp);  // sort using a custom comparator
	for(int i=0; i<n; ++i) cout<<a[i]<<' ';
	cout<<endl<<endl;
	
	/*
	Custom comparator for a vector of pair of integers
	*/
	int n2;
	cin>>n2;
	vector<pair<int, int>> v(n2);
	for(int i=0; i<n2; ++i) cin>>v[i].first>>v[i].second;
	sort(v.begin(), v.end(), cmp_pairs);  // sort using a custom comparator for pairs
	for(int i=0; i<n2; ++i) cout<<v[i].first<<' '<<v[i].second<<endl;
}