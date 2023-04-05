#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	Method-1: storing the inputs as it is

	map<int, multiset<string>> marks_map;
	int n;
	cin>>n;
	while(n--){
		string name;
		int marks;
		cin>>name>>marks;
		marks_map[marks].insert(name);
	}

	auto cur_it = --marks_map.end();

	while(true){
		int marks = cur_it->first;
		auto &students = cur_it->second;
		for(auto student: students){
			cout<<student<<" "<<marks<<endl;
		}
		if (cur_it == marks_map.begin()) break;
		cur_it--;
	}

	*/

	// (or)

	/*
	Method-2: storing the negative of the input values
	*/

	map<int, multiset<string>> marks_map;
	int n;
	cin>>n;
	while(n--){
		string name;
		int marks;
		cin>>name>>marks;
		marks_map[-1*marks].insert(name);
	}

	for(auto marks_students_pr: marks_map){
		int marks = marks_students_pr.first;
		auto &students = marks_students_pr.second;
		for(auto student: students){
			cout<<student<<" "<<-1*marks<<endl;
		}
	}
}