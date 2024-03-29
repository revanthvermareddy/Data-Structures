#include<bits/stdc++.h>
using namespace std;

// formula: for n elements there will be 2^n subsets
vector<vector<int>> allSubsets;

void generate(vector<int> &subset, int i, vector<int> &nums){
	if (i == nums.size()){
		allSubsets.push_back(subset);
		return;
	}

	// ith element not in subset
	generate(subset, i+1, nums);

	// ith element in subset
	subset.push_back(nums[i]);
	generate(subset, i+1, nums);
	subset.pop_back();  // this step is called back tracking
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0; i<n; ++i){
		cin>>nums[i];
	}
	vector<int> empty;
	generate(empty, 0, nums);
	for(auto subset: allSubsets){
		for(auto ele: subset){
			cout<<ele;
		}
		cout<<endl;
	}
}