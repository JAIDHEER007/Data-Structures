//Stack data structure using linked list

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff/2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

class node{
	public:
		int data;
		node* next;
		
		node(){
			data = 0;
			next = NULL;
		}
		node(int val){
			data = val;
			next = NULL;
		}
};

string to_string(node *address){
	stringstream ss;
	ss << address;
	return ss.str();
}

class stack{
	private:
		node *top;
	public:
		stack(){
			top = NULL;
		}
		stack(vector<int> &input_arr){
			top = NULL;
			for(int input_element:input_arr)
				push(input_element);
		}
		
		void push(int value);
		void push(vector<int> &input_arr);
		void pop();
		
		int peek();
		bool isEmpty();
		int size();
		
		void print();
		void print_debug();
};

void stack::push(int val){
	node *temp = new node(val);
	if(top != NULL)
		temp -> next = top;
	top = temp;
}

void stack::push(vector<int> &input_arr){
	for(int input_element:input_arr)
		push(input_element);
}

void stack::pop(){
	if(top == NULL){
		cout<<"Stack is empty. Nothing to pop!!"<<endl;
		return;
	}else{
		node* temp = top;
		top = top -> next;
		delete(temp);
	}
}

//use in combination with isEmpty() function. 
int stack::peek(){
	return top->data;
}

bool stack::isEmpty(){
	return (top==NULL);
}

void stack::size(){
        int len = 0;
	node *temp = top;
	while(temp!=NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}

void stack::print(){
	if(top == NULL){
		cout<<"Stack is empty. Nothing to print!!"<<endl;
		return;
	}
	node *temp = top;
	while(top != NULL){
		cout<<top->data<<" -> ";
		top = top -> next;
	}
	cout<<"END"<<endl;
}

void stack::print_debug(){
	if(isEmpty()){
		cout<<"Stack is empty. Nothing to print!!"<<endl;
		return;
	}
	int s_no = 1;
	node *temp = top;
	
	cout<<string(75,'-')<<endl;
	cout<<"|"<<center(10,"Node_No")<<"|"<<center(20,"Address")<<"|"<<center(20,"Next")<<"|"<<center(20,"Data")<<"|"<<endl;
	cout<<string(75,'-')<<endl;
	while(temp != NULL){
		cout<<"|"<<center(10,to_string(s_no))<<"|"<<center(20,to_string(temp))<<"|"<<center(20,to_string(temp->next))<<"|"<<center(20,to_string(temp->data))<<"|"<<endl;
		temp = temp -> next;
		s_no++;
	}
	cout<<string(75,'-')<<endl;
}

int main(){
	stack s1;
	
	cout<<s1.isEmpty()<<endl;
	
	//cout<<s1.peek()<<endl; 
	//Dont do it.
	
	s1.print_debug();
	s1.pop();
	
	s1.push(553);
	s1.push(554);
	s1.push(555);
	
	cout<<s1.isEmpty()<<endl;
	s1.print_debug();
	cout<<s1.peek()<<endl;
	
	s1.pop();
	
	s1.print_debug();
	
	vector<int> input_arr{111, 108, 200, 15, 132, 199, 175, 140, 69, 63};
	
	stack s2(input_arr);
	
	s2.print_debug();
	
	vector<int> input_arr2{106, 56, 90, 71, 26, 99, 185, 1, 157, 113};
	
	stack s3;
	
	s3.push(input_arr2);
	
	s3.print();
	
	return 0;
}
