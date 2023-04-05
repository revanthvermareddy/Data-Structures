#include<bits/stdc++.h>
using namespace std;


/*
Stack: is a LIFO(Last In First Out) data structure

Stacks are used to solve:
(({}))[()] - Balanced Paranthesis
NGE - Next Greater Element

Operations:
- push()
- pop()
- top()

*/

/*
Queue: is a FIFO(First In First Out) data structure

Queues are used to solve:
BFS - Breadth First Search

Operations:
- push(): which is equivalent to enqueue()
- pop(): which is equivalent to dequeue()
- front()
*/


int main(){
	// Stack
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	// Queue
	queue<string> q;
	q.push("abc");
	q.push("bcd");
	q.push("cde");
	q.push("def");
	q.push("efg");
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	
}