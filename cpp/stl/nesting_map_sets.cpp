#include<bits/stdc++.h>
using namespace std;

int main(){

	// map is generally ordered -> uses RBT (Red Black Tree) -> any input that supports comparators can be passed -> hence nesting possible

	// map<pair<int, int>, int> m1;
	pair<int, int> p1, p2;
	
	// Ex-1: compare first elements
	p1 = {1, 2};
	p2 = {2, 3};

	cout<<"pair comparision-1: "<<(p1<p2)<<endl;

	// Ex-1: compare second elements
	p1 = {2, 2};
	p2 = {2, 3};

	cout<<"pair comparision-2: "<<(p1>p2)<<endl;

	// map<set<int>, int> m2;
	set<int> s1, s2;

	s1 = {1, 6, 5};
	s2 = {4, 6, 7, 1};

	cout<<"set comparision: "<<(s1<s2)<<endl;

	cout<<endl;
	map<pair<string, string>, vector<int>> m3;
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		string fn, ln;
		int ct;
		cin>>fn>>ln>>ct;
		cout<<"input: "<<fn<<ln<<ct<<endl;
		for(int j=0; j<ct; ++j){
			int x;
			cin>>x;
			m3[{fn, ln}].push_back(x);
		}
	}


	// IMP: If we do not use '&' then elements will be copied which is a costly operation for vectors etc O(n) time complexity 
	for(auto &pr: m3){
		auto &full_name = pr.first; // pr.first: is a pair & pr.first.first: is the first name & pr.first.second: is the last name
		auto &list = pr.second;     // pr.second: is a vector
		cout << full_name.first << " " << full_name.second <<endl;
		cout << list.size() << endl;
		for(auto &element: list){
			cout<<element<<" ";
		}
		cout<<endl;
	}


}