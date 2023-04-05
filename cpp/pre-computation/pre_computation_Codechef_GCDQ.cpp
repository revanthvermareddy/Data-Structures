/*
Codechef GCDQ: https://www.codechef.com/problems/GCDQ

You are given an array A of integers of size N. 
You will be given Q queries where each query is represented by two integers L, R. 
You have to find the gcd(Greatest Common Divisor) of the array after excluding 
the part from range L to R inclusive (1 Based indexing). 
You are guaranteed that after excluding the part of the array remaining array is non empty.

Input:
First line of input contains an integer T denoting number of test cases.
For each test case, first line will contain two space separated integers N, Q.
Next line contains N space separated integers denoting array A.
For next Q lines, each line will contain a query denoted by two space separated integers L, R.

Output:
For each query, print a single integer representing the answer of that query.

Constraints:

Subtask #1: 40 points
2 ≤ T, N ≤ 100, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 10^5
1 ≤ L, R ≤ N and L ≤ R

Subtask #2: 60 points
2 ≤ T, N ≤ 10^5, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 10^5
1 ≤ L, R ≤ N and L ≤ R
Sum of N over all the test cases will be less than or equal to 10^6.

Warning : Large IO(input output), please use faster method for IO.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	/*
	Method-1: Without using pre-computation of GCD
	

	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		int a[n+10];
		for(int i=1; i<=n; ++i){
			cin>>a[i];
		}

		while(q--){
			int l, r;
			cin>>l>>r;
			int gc = 0;
			for(int i=1; i<=l-1; ++i){
				gc = __gcd(gc, a[i]);  // TC: __gcd(a, b) = O(log(max(a,b)))
			}
			for(int i=r+1; i<=n; ++i){
				gc = __gcd(gc, a[i]);  // TC: __gcd(a, b) = O(log(max(a,b)))
			}
			cout<<gc<<endl;
		}
	}

	// TC: O(T*(N + Q*N*log(A[i])) = O(T*N + T*Q*N*log(A[i]))
	// in subtask-1: O(T*N + T*Q*N*log(A[i])) = 100^3 = 10^6 < 1 Sec [pass]
	// in subtask-2: O(T*N + T*Q*N*log(A[i])) = O(10^6 + 10^6*10^5) = 10^6 + 10^11 = 10^11 > 1 Sec [fail]
	*/

	/*
	Method-1: With using pre-computation of GCD
	*/
	
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		int a[n+10];
		int forward[n+10];
		int backward[n+10];
		forward[0] = backward[n+1] = 0;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
		}

		// forward pre-computation of gcd
		for(int i=1; i<=n; ++i){
			forward[i] = __gcd(forward[i-1], a[i]);  // TC: __gcd(a, b) = O(log(max(a,b)))
		}

		// backward pre-computation of gcd
		for(int i=n; i>=1; --i){
			backward[i] = __gcd(backward[i+1], a[i]);  // TC: __gcd(a, b) = O(log(max(a,b)))
		}

		while(q--){
			int l, r;
			cin>>l>>r;
			int gc = 0;
			cout<<__gcd(forward[l-1], backward[r+1])<<endl;
		}
	}
	// TC: O(T*(N + N*log(A[i]) + Q)) = O(T*N + T*N*log(A[i]) + T*Q) = O(T*N + T*Q) = O(T*N)
	// in subtask-1: O(T*N) = 100^2 = 10^4 < 1 Sec [pass]
	// in subtask-2: O(T*N) = 10^6 (as given in the stmnt) < 1 Sec [pass]
}

