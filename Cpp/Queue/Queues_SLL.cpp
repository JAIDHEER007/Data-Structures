//Queue data structure using linked list

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

class queue{
	private:
		node *front, *back;
	public:
		queue(){
			front = back = NULL;
		}
		
		queue(vector<int> &input_arr){
			front = back = NULL;
			for(int input_element:input_arr)
				enqueue(input_element);
		}
		
		void enqueue(int val);
		void enqueue(vector<int> &input_arr);
		void dequeue();
		
		bool isEmpty();
		int size();
		void print_debug();
		void print();
};

void queue::enqueue(int val){
	node *temp = new node(val);
	
	if(isEmpty())
		front = back = temp;
	else{
		back->next = temp;
		back = temp;
	}
}

void queue::enqueue(vector<int> &input_arr){
	for(int input_element:input_arr)
		enqueue(input_element);
}

void queue::dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to delete!!"<<endl;
		return;
	}else if(front == back){	//Single Element
		delete(front);
		front = back = NULL;	
	}else{
		node *temp = front;
		front = front -> next;
		delete(temp);
	}
	
}

inline bool queue::isEmpty(){
	return ((front == NULL) && (back == NULL));
}

int queue::size(){
	int len = 0;
	node *temp = front;
	while(temp!=NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}

void queue::print_debug(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to print!!"<<endl;
		return;
	}
	int s_no = 1;
	node *temp = front;
	
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

void queue::print(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to print!!"<<endl;
		return;
	}
	node *temp = front;
	while(temp != NULL){
		cout<<temp -> data<<" -> ";
		temp = temp -> next;
	}
	cout<<"END"<<endl;
}

int main(){
	vector<int> input_arr{144, 190, 97, 1, 160, 134, 176, 67, 73, 151};
	
	queue q1(input_arr);
	
	cout<<boolalpha<<q1.isEmpty()<<endl;
	
	q1.print_debug();
	
	q1.dequeue();
	
	q1.print_debug();
	
	cout<<q1.size()<<endl;
	
	q1.print();
	
	return 0;
}
