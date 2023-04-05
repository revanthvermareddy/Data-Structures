/*
Luffy is very obsessed with plaindromes. 
Given a string S of lower case English alphabet of length N and two
integers L and R he wants to know whether all the letters of the substring
from index L to R (L and R included) can be rearranged to form a palindrome
or not. He wants to know this for Q values of L and R and
needs your help in finding answer.

Constraints:
1 <= t <= 10
1 <= N,Q <= 100000
1 <= L <= R <= N
'a' <= S[i] <= 'z' for 1 <= i<= N

Input:
First line contains an integer t denoting the number of test cases.
First line of each test case contains 2 space seperated inetegers N and Q, the length of the string and the number of queries resp.
Next line contains the string S.
Each of the Next Q lines contain 2 spaces seperated integers L and R.
*/

// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int N = 1e5+10;
int hsh[26][N];

int main(){
	/*
	Method:1 Using hashing but not with prefix sum
	
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		string s;
		cin>>s;  // TC: O(n)
		while(q--){
			int l, r;
			cin>>l>>r;
			int hsh[26];
			for(int i=0; i<26; ++i){
				hsh[i] = 0;
			}
			l--;r--;
			for(int i=l; i<=r; ++i){
				hsh[s[i] - 'a']++;
			}
			int oddCt = 0;
			for(int i=0; i<26; ++i){
				if (hsh[i]%2 != 0) oddCt++;
			}
			if (oddCt>1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}

	// TC: O(t*(n + q*(26 + n + 26))) = O(t*n + t*q*(26 + n + 26))) = O(t*q*n) = 10*10^5*10^5 = 10^11 > 1 sec
	*/

	/*
	Method:2 Using hashing along with prefix sum
	*/

	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;

		string s;
		cin>>s;  // TC: O(n)

		// clear the hash array for each test case
		for(int i=0; i<26; ++i){
			for(int j=1; j<=n; ++j){
				hsh[i][j] = 0;
			}
		}

		// Pre-Compute
		// a 1-based hash array holding the count of each char count in corresponding column value of a 2D-array
		for(int i=0; i<n; ++i){
			hsh[s[i]-'a'][i+1]++;
		}

		// get prefix-sum for each character
		for(int i=0; i<26; ++i){
			for(int j=1; j<=n; ++j){
				hsh[i][j] += hsh[i][j-1];
			}
		}

		while(q--){
			int l, r;
			cin>>l>>r;
			int oddCt = 0;

			for(int i=0; i<26; ++i){
				int charCt = hsh[i][r] - hsh[i][l-1];
				if (charCt%2 != 0) oddCt++;
			} 

			if (oddCt>1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}

	// TC: O(t*(n + n + 26*n + q*26)) = O(2*t*n + t*q*26 + t*n*26) = O(t*n) = 10*10^5 = 10^6 < 1 sec
}
