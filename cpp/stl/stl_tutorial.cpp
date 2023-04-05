/*

STL -> 4 parts

1.) Containers
2.) Iterators
3.) Algorithms
4.) Functors


1.) Containers

	a. Sequential
		- vectors
		- stack
		- queue
		- pair (not a container)

	b. Ordered
		- maps
		- multimap
		- set
		- multiset

	c. Unordered
		- unordered map
		- unordered set
	
	---

	Type: Nested Containers
		- ventor<vector<int>>
		- map<int, vector<int>>
		- set<pair<int,string>>
		- vector<map<int,set<int>>>

2.) Iterators (similar to pointers)

	- point to memory address of containers
	- begin(), end()
	- vector<int>::iterator it;
	- continuity for containers

3.) Algorithms

	- upper bound
	- lower bound
	- sort(comparator)
	- max_element
	- min_element
	- accumulate
	- reverse
	- count
	- find
	- next permutation
	- prev permutation

4.) Functors
	
	- classes which can act as functions

*/

