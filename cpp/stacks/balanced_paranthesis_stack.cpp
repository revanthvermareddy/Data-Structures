#include<bits/stdc++.h>
using namespace std;


unordered_map<char, int> symbols = {
	{'[', -1},
	{'{', -2},
	{'(', -3},
	{')', 3},
	{'}', 2},
	{']', 1}
};

string isBalanced(string s){
	stack<char> st;
	for(char bracket: s){
		if(symbols[bracket]<0) st.push(bracket);
		else{
			if (st.empty()) return "No";
			char top = st.top();
			st.pop();
			if (symbols[top]+symbols[bracket] != 0) return "No";
		}
	}
	// Finally, check if stack is empty
	if(st.empty()) return "Yes";
	return "No";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<isBalanced(s)<<endl;
	}
}