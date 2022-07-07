//stack in STL

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	stack<int> s1;
	
	cout<<s1.empty()<<endl;
	
//	cout<<s1.top()<<endl;
//	Don't do it 
//	Leads to segmentation fault
	
	s1.push(553);
	s1.push(554);
	s1.push(555);
	
	cout<<s1.size()<<endl;
	
	while(!s1.empty()){
		cout<<s1.top()<<" -> ";
		s1.pop();
	}cout<<"END"<<endl;
	
	vector<int> input_arr{111, 108, 200, 15, 132, 199, 175, 140, 69, 63};
	
	stack<int,vector<int>> s2(input_arr);
	
	cout<<s2.size()<<endl;
	
	while(!s2.empty()){
		cout<<s2.top()<<" -> ";
		s2.pop();
	}cout<<"END"<<endl;
	
	return 0;
}

