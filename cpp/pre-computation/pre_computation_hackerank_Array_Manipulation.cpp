/*
hacker rank: https://www.hackerrank.com/challenges/crush/problem

Starting with a 1-indexed array of zeros 
and a list of operations, for each operation 
add a value to each the array element between 
two given indices, inclusive. Once all operations 
have been performed, return the maximum value in the array.

Input Format:
The first line contains two space-separated integers n and m, the size of the array and the number of operations.
Each of the next m lines contains three space-separated integers a, b and k, the left index, right index and summand.

Constraints:
3 <= n <= 10^7
1 <= m <= 2*10^5
1 <= a <= b <= n
0 <= k <= 10^9

Sample Input:
5 3
1 2 100
2 5 100
3 4 100
*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
long long int ar[N];  // long long int as range of m*k = 2*10^5*10^9 = 2*10^14

int main(){
	/*
	Method-1: Without using prefix-sum and hashing

	int n, m;
	cin>>n>>m;
	while(m--){
		int a,b,k;
		cin>>a>>b>>k;
		for(int i=a; i<=b; ++i){
			ar[i] += k;
		}
	}
	long long mx = -1;

	for(int i=1; i<=n; ++i){
		if (mx<ar[i]){
			mx = ar[i];
		}
	}
	cout<<mx<<endl;

	// TC: O(m*n + n) = O(m*n) = 2*10^5*10^7 = 2*10^12 > 1 sec [fail]
	*/

	/*
	Method-2: With using prefix-sum and hashing
	*/

	int n, m;
	cin>>n>>m;
	while(m--){
		int a,b,k;
		cin>>a>>b>>k;
		ar[a] += k;
		ar[b+1] -= k;
	}

	// prefix-sum
	for(int i=1; i<=n; ++i){
		ar[i] += ar[i-1];
	}

	// find maximum value
	long long mx = -1;
	for(int i=1; i<=n; ++i){
		if (mx<ar[i]){
			mx = ar[i];
		}
	}
	cout<<mx<<endl;

	// TC: O(m+n) = 2*10^5 + 10^7 = 10^7 < 1 sec [pass]
}
