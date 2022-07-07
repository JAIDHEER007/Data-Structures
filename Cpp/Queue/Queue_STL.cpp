//Queue data structure in STL

#include<iostream>
#include<list> 
#include<queue>

using namespace std;

int main(){
	queue<int> q1;
	
	cout<<q1.empty()<<endl;
	
	q1.push(553);
	q1.push(554);
	q1.push(555);
	
	cout<<q1.empty()<<endl;
	cout<<q1.front()<<" "<<q1.back()<<endl;
	cout<<q1.size()<<endl;
	
	q1.pop();
	
	cout<<q1.empty()<<endl;
	cout<<q1.front()<<" "<<q1.back()<<endl;
	cout<<q1.size()<<endl;
	
	//Only List and Deque can be used as underlying container
	
	list<int> input_arr{144, 190, 97, 1, 160, 134, 176, 67, 73, 151};
	
	queue<int, list<int>> q2(input_arr);
	
	cout<<q2.empty()<<endl;
	cout<<q2.front()<<" "<<q2.back()<<endl;
	cout<<q2.size()<<endl;
	
	while(!q2.empty()){
		cout<<q2.front()<<" -> ";
		q2.pop();
	}cout<<"END"<<endl;
	
	cout<<q2.empty()<<endl;
	cout<<q2.size()<<endl;
	
	return 0;
}
