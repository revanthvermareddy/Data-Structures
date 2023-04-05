#include<bits/stdc++.h>
using namespace std;

vector<string> valid;

// backtracking is type of recursion

void generate(string &s, int open, int close){  // IMP: pass by reference as copy of string take O(n) time
	if(open==0 && close==0){
		valid.push_back(s);
		return;
	}

	if(open>0){
		s.push_back('(');
		generate(s, open-1, close);
		s.pop_back();  // this step is called back tracking
	}

	if(close>0 && close>open){
		s.push_back(')');
		generate(s, open, close-1);
		s.pop_back();  // this step is called back tracking
	}
}

int main(){
	int n;
	cin>>n;
	string s;
	generate(s, n, n);
	for(auto ele: valid){
		cout<<ele<<endl;
	}
}