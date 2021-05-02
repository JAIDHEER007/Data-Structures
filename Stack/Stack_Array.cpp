//Implementing Stack data structure using Arrays
//Within classes


#include<iostream>
#define MAX 1000
using namespace std;

class Stack{
	private:
		int top = -1;
		int *arr = new int[MAX];
	
	public:
		void push(int value);
		void pop();
		void peek();
		void isEmpty();
		void print();
		
		~Stack(){
			delete(arr);
		}
};

void Stack::push(int value){
	if(top >= MAX - 1){
		cout<<"Overflow!!"<<endl;
		return;
	}
	else{
		arr[++top] = value;
		cout<<value<<" successfully pushed to stack"<<endl;
	}
}

void Stack::pop(){
	if(top < 0){
		cout<<"Stack is empty. Nothing to delete!!"<<endl;
		return;
	}
	else{
		cout<<arr[top--]<<" deleted from the stack!!"<<endl;
	}
}

void Stack::peek(){
	if(top < 0){
		cout<<"Stack is Empty!!"<<endl;
		return;
	}
	else{
		cout<<"Top element: "<<arr[top]<<endl;;
	}
}

void Stack::isEmpty(){
	if(top < 0){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	else if(top >= (MAX - 1)){
		cout<<"Stack is FULL"<<endl;
		return;
	}
	else{
		cout<<"Stack is not empty"<<endl;
	}
}

void Stack::print(){
	if(top < 0){
		cout<<"Stack is Empty. Nothing to Print"<<endl;
		return;
	}
	else{
		cout<<"Elements of stack: "<<endl;
		for(int i = top; i >= 0; i--){
			cout<<arr[i]<<endl;
		}
		cout<<"END"<<endl;
	}
}

int main(){
	Stack s1;
	
	s1.print();
	s1.peek();
	s1.pop();
	s1.isEmpty();
	
	s1.push(553007);
	s1.push(553);
	s1.push(1980);
	
	s1.print();
	s1.peek();
	s1.isEmpty();
	
	s1.pop();
	s1.print();
	s1.pop();
	s1.pop();
	s1.pop();
	
	return 0;
}

