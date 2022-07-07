//Printing a STL stack without changing the order.

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void print_with_damage(stack<int> &stk){
	while(!stk.empty()){
		cout<<stk.top()<<" -> ";
		stk.pop();
	}cout<<"END"<<endl;
}

//Pinting without damage using Recursion

void print_Bottom_to_Up(stack<int> &stk){
	if(stk.empty())
		return;
	
	int stk_top = stk.top();
	
	stk.pop();
	
	print_Bottom_to_Up(stk);
	
	cout<<stk_top<<" -> ";
	
	stk.push(stk_top);
}

void print_Up_to_Bottom(stack<int> &stk){
	if(stk.empty())
		return;
	
	int stk_top = stk.top();
	
	cout<<stk_top<<" -> ";
	
	stk.pop();
	
	print_Up_to_Bottom(stk);
	
	stk.push(stk_top);
}

int main(){
	vector<int> input_arr{320, 139, 422, 188, 389, 56, 559, 14, 100, 21};
	
	stack<int> stk1;
	
	for(int input_element:input_arr)
		stk1.push(input_element);
	
	print_with_damage(stk1);
	
	cout<<"Is Empty: "<<boolalpha<<stk1.empty()<<endl;
	
	for(int input_element:input_arr)
		stk1.push(input_element);
	
	print_Bottom_to_Up(stk1);
	cout<<"END"<<endl;
	
	cout<<"Is Empty: "<<boolalpha<<stk1.empty()<<endl;
	
	print_Up_to_Bottom(stk1);
	cout<<"END"<<endl;
	
	cout<<"Is Empty: "<<boolalpha<<stk1.empty()<<endl;
	
	return 0;
}
