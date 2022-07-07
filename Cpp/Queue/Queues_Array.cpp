//Implementing Queues using Arrays in class

#include<iostream>
#define MAX 5
using namespace std;

class Queue{
	int *arr = new int[MAX];
	int front, rear;
	
	public:
		
		Queue(){
			front = rear = -1;
		}
		bool isFull();
		bool isEmpty();
		
		void enqueue(int value);
		void dequeue();
		
		void print();
		void printRear();
		void printFront();
		void debug();
			
		~Queue(){
			delete(arr);
		}
};

bool Queue::isFull(){
	if(rear == MAX -1)
		return true;
	else
		return false;
}

bool Queue :: isEmpty(){
	if((front == -1) && (rear == -1))
		return true;
	else
		return false;
}

void Queue :: enqueue(int value){
	if(isFull()){
		cout<<"Queue is Full. Cannot enqueue!!"<<endl;
		return;
	}else{
		if(front == -1)
			front = 0;
		rear++;
		arr[rear] = value;
		cout<<value<<" successfully enqueued!!"<<endl;
	}
}

void Queue :: dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty. Cannot dequeue!!"<<endl;
		return;
	}else{
		int deleted_value = arr[front];
		if(front == rear){	//only one element
			front = rear = -1;
		}
		else{
			front++;
		}
		cout<<"successfully deleted "<<deleted_value<<endl;
	}
}

void Queue :: printFront(){
	cout<<"Front: "<<front<<endl;
}

void Queue :: printRear(){
	cout<<"Rear: "<<rear<<endl;
}

void Queue :: debug(){
	cout<<"\n------------------------- DEBUG OUTPUT -------------------------"<<endl;
	(isEmpty())?(cout<<"Empty Queue"):(cout<<"Not an Empty Queue"); cout<<endl;
	(isFull())?(cout<<"Queue is Full"):(cout<<"Queue is not Full"); cout<<endl;
	print();
	printFront();
	printRear();
	cout<<"----------------------------- END ------------------------------"<<endl<<endl;
}

void Queue :: print(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to print"<<endl;
		return;
	}
	else{
		cout<<"Elements of Queue: "<<endl;
		for(int i = front; i <= rear; i++)
			cout<<arr[i]<<"  ";
		cout<<"End"<<endl;
	}
}

int main(){
	Queue q1;
	
	//Follow this specific order to see disadvantage of normal Queue
	
	q1.debug();
	
	q1.enqueue(2);
	
	q1.debug();
	
	q1.dequeue();
	
	q1.debug();
	
	q1.enqueue(2);
	q1.enqueue(3);
	
	q1.debug();
	
	q1.dequeue();
	
	q1.debug();
	
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	q1.debug();
	
	q1.enqueue(7);
	
	q1.debug();
	
	q1.enqueue(8);
	
	q1.debug();
	
	q1.enqueue(9);
	
	q1.debug();
	
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	
	q1.debug();
	
	q1.enqueue(10);
	
	q1.debug();
	
	return 0;
}
