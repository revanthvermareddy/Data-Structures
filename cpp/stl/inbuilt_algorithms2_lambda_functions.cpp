#include<bits/stdc++.h>
using namespace std;

/*

3 boolean algorithms:

all_of(): checks the condition on every element without loop and returns true if its satisfied by all else returns false if its violated by even one element
none_of(): checks the condition on every element without loop and returns true if its not satisfied by all else returns false if its violated by even one element
any_of(): checks the condition on every element without loop and returns true if its satisfied by atleast one element else returns false if its violated by all the elements

*/

bool isPositive(int x){
	return x > 0;
}

int main(){
	// lambda_function: [](int x){return x+2;}
	// lambda_function calling with an argument: [](int x){return x+2;}(argument)
	cout << [](int x){return x+2;}(2) << endl;
	cout << [](int x){return x+2;}(4) << endl;
	cout << [](int x){return x+2;}(6) << endl;

	cout << [](int x, int y){return x+y;}(6, 7) << endl;

	// reuse the lambda function by assiginig to a variable using auto keyword
	auto sum = [](int x, int y){return x+y;};  // here sum is a function
	cout<<sum(2, 3)<<endl;

	vector<int> v = {2, 3, -4, 5};

	// 1. all_of
	cout<<all_of(v.begin(), v.end(), [](int x){return x>0;})<<endl;
	// cout<<all_of(v.begin(), v.end(), isPositive)<<endl;
	
	// 3. none_of
	cout<<none_of(v.begin(), v.end(), [](int x){return x>0;})<<endl;
	
	// 3. any_of
	cout<<any_of(v.begin(), v.end(), [](int x){return x>0;})<<endl;
	
	// check if all the elements are even
	cout<<all_of(v.begin(), v.end(), [](int x){return x%2==0;})<<endl;
}