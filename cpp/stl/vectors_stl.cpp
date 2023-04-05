#include<bits/stdc++.h>
using namespace std;

// vectors are similar to array's
// vector is a continuous block's of memory
// but vector has a dynamic size unlike array's which have a fixed pre-declared size

void printVector(vector<int> &v){ // here we are passing the vector by reference, as without '&' it would take more O(n) time for copying
	cout<<"size: "<<v.size()<<endl;
	for(int i=0; i<v.size(); ++i){  // TC: v.size() -> O(1)
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> v;

	int n;
	cin>>n;

	for(int i=0; i<n; ++i){
		int x;
		cin>>x;
		printVector(v);
		v.push_back(x);  // TC: O(1)
	}

	v.push_back(7);  // TC: O(1)
	printVector(v);
	v.pop_back();  // TC: O(1)
	printVector(v);

	// copy but not by reference
	vector<int> v2 = v;  // TC: O(n)
	v2.push_back(5);
	printVector(v);
	printVector(v2);


}