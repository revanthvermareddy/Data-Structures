#include<bits/stdc++.h>
using namespace std;

// function for factorial(n)
int fact(int n){
	if(n==0) return 1;
	return fact(n-1)*n;
}

int main(){
	int n;
	cin>>n;
	cout<<fact(n);
}

/*
TC of a recursive function:
1. Number of function calls
2. What is time complexity of each function

Ans-1: n
Ans-2: O(1)
Overall TC: n*O(1) = O(n)
*/