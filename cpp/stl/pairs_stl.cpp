#include<bits/stdc++.h>
using namespace std;

int main(){
	pair<int, string> p;

	// There are 2 ways to init elememts onto the pair

	// 1. using function called make_pair
	p = make_pair(1, "revanth-1");
	cout<<p.first<<" "<<p.second<<endl;

	// 2. using curly brace syntax
	p = {2, "revanth-2"};
	cout<<p.first<<" "<<p.second<<endl;

	// copy by value
	pair<int, string> p1 = p;
	p1.first = 3;
	p1.second = "revanth-3";
	cout<<p.first<<" "<<p.second<<endl;

	// copy by reference
	pair<int, string> &p2 = p;
	p2.first = 3;
	p2.second = "revanth-3";
	cout<<p.first<<" "<<p.second<<endl;


	// pairs usage:
	int a[] = {1, 2, 3};
	int b[] = {2, 3, 4};

	pair<int, int> p_array[3];  // in general we use vector<pair<int, int>> and do not declare like this 

	p_array[0] = {1, 2};
	p_array[1] = {2, 3};
	p_array[2] = {3, 4};

	// swap operation on pair array elements
	swap(p_array[0], p_array[2]);

	for(int i=0; i<3; ++i){
		cout<<p_array[i].first<<" -> "<<p_array[i].second<<endl;
	}

	// taking user input
	cin >> p.first;
	cout<< p.first;


}