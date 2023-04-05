#include<bits/stdc++.h>
using namespace std;

// def of lower_bound: returns the element index if its present in the array else returns the next greater element index
// returns the index of the element which is the lower bound of the given element
int lower_bound(vector<int> &v, int element){
	// here we use binary search assuming its a monotonous function
	int lo = 0, hi = v.size()-1;
	while (hi-lo > 1){
		int mid = (hi+lo)/2;
		if (v[mid] < element) {
			lo = mid + 1;
		} else {
			hi = mid; 
		}
	}
	if (v[lo] >= element){
		return lo;
	}
	if (v[hi] >= element){
		return hi;
	}
	return -1;
}


// def of upper_bound: returns the element index which is strictly the next greater element than the element passed
// returns the index of the element which is the upper bound of the given element
int upper_bound(vector<int> &v, int element){
	// here we use binary search assuming its a monotonous function
	int lo = 0, hi = v.size()-1;
	while (hi-lo > 1){
		int mid = (hi+lo)/2;
		if (v[mid] <= element) {
			lo = mid + 1;
		} else {
			hi = mid; 
		}
	}
	if (v[lo] > element){
		return lo;
	}
	if (v[hi] > element){
		return hi;
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	
	// Implement upper bound and lower bound for a given element
	int element;
	cin>>element;
	int lb = lower_bound(v, element);
	cout<<lb<<" "<<(lb != -1 ? v[lb] : -1)<<endl;
	int ub = upper_bound(v, element);
	cout<<ub<<" "<<(ub != -1 ? v[ub] : -1)<<endl;

}