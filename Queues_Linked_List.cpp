//Implementing Queue using Linked List in classes

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class Queue : protected Node{
	
	Node *front, *rear;
	public:
		Queue(){
			front = rear = NULL;
		}
		
		void enqueue(int value);
		void dequeue();
		
		bool isEmpty();
		void print();
};

void Queue::enqueue(int value){
	Node *temp = new Node;
	temp -> data = value;
	temp -> next = NULL;
	
	if(isEmpty()){
		front = rear = temp;
	}
	else{
		rear -> next = temp;
		rear = temp;
	}
}

void Queue :: dequeue(){
	if(isEmpty()){
		cout<<"Queue is Empty. Nothing to delete!!"<<endl;
		return;
	}else{
		if(front == rear){ //Single element
			delete(front);
			front = rear = NULL;
		}else{
			Node *temp = front;
			front = front -> next;
			delete(temp);
		}
	}
}

bool Queue :: isEmpty(){
	if((front == NULL) && (rear == NULL))	
		return true;
	else
		return false;
}

void Queue :: print(){
	if(isEmpty()){
		cout<<"Queue is Empty. Nothing to print!!"<<endl;
		return;
	}else{
		Node *temp = front;
		cout<<endl<<"Elements of Queue: "<<endl;
		while(temp != NULL){
			cout<<temp -> data <<endl;
			temp = temp -> next;
		}
		cout<<"END"<<endl;
	}
}

int main(){
	Queue q1;
	
	cout<<q1.isEmpty()<<endl;
	q1.print();
	q1.dequeue();
	
	q1.enqueue(553);
	cout<<q1.isEmpty()<<endl;
	q1.print();
	
	q1.dequeue();
	cout<<q1.isEmpty()<<endl;
	q1.print();
	
	q1.enqueue(553);
	q1.enqueue(553007);
	q1.enqueue(1980);
	q1.enqueue(777);
	
	q1.print();
	
	q1.dequeue();
	q1.print();
	
	q1.dequeue();
	q1.dequeue();
	q1.print();
	
	q1.dequeue();
	q1.dequeue();
	q1.print();
	
	return 0;
}
