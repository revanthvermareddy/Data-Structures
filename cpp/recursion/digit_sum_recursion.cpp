#include<bits/stdc++.h>
using namespace std;

// digitSum(n) -> gives the sum of digits of integer n
// digitSum(n) = n%10 + digitSum(n/10)

int digitSum(int n){
	if (n==0) return 0;
	return digitSum(n/10) + (n % 10);
}

int main(){
	int n;
	cin>>n;
	cout<<digitSum(n);
	
	// TC: 
	// 1. number of digits in n -> log(n)
	// 2. TC for each function call -> O(1)
	// Overall TC: O(log(n))
}