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
		void enqueue(int value);
		void dequeue();
		
		bool isFull();
		bool isEmpty();
		
		void print();
		
		~Queue(){
			delete(arr);
		}
};

void Queue :: enqueue(int value){
	if(isFull()){
		cout<<"Queue is Full!!"<<endl;
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
		cout<<"Queue is empty"<<endl;
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

bool Queue::isFull(){
	if((front == 0) && (rear == MAX -1))
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

void Queue :: print(){
	if(isEmpty()){
		cout<<endl<<"Queue is empty. Nothing to print"<<endl;
		return;
	}
	else{
		cout<<"Elements of Queue: "<<endl;
		for(int i = front; i <= rear; i++){
			cout<<arr[i]<<endl;
		}
		cout<<"End"<<endl<<endl;
	}
}

int main(){
	Queue q1;
	
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	q1.print();
	q1.dequeue();
	
	q1.enqueue(2);
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	q1.print();
	
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	q1.print();
	
	q1.dequeue();
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	q1.print();
	
	q1.enqueue(2);
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	q1.print();
	
	return 0;
}
