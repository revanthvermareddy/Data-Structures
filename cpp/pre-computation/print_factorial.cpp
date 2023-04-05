/*
Given T test cases and in each
test case a number N. Print its factorial
for each test case % M.
where M = 10^9+7

Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 1e5+10;
int fact[N];

int main(){
	/*
	Method-1: Without pre-computation

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		long long fact = 1;
		for(int i=2; i<=n; ++i){
			fact = (fact*i)%M;
		}
		cout<<fact<<endl;
	}

	// TC: O(T*N) = O(N^2) = 10^10 > 1 sec
	*/
	
	/*
	Method-2: Using pre-computation
	*/

	fact[0] = fact[1] = 1;
	for(int i=2; i<N; ++i){
		fact[i] = (fact[i-1]*i)%M;
	}

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		cout<<fact[n]<<endl;
	}

	// TC: O(N) + O(T) = 2*O(N) = O(N) = 10^5 < 1 sec
}