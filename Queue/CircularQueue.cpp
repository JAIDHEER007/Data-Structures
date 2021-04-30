#include<iostream>
#define MAX 5
using namespace std;

class CircularQueue{
	int* arr = new int[MAX];
	int front, rear;
	
	public:
		CircularQueue(){
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
			
		~CircularQueue(){
			delete(arr);
		}
};

bool CircularQueue::isFull(){
	if((front==0)&&(rear==MAX-1))
		return true;
	if(front==rear+1)
		return true;
	return false;
}

bool CircularQueue::isEmpty(){
	return ((front == -1) && (rear == -1));
}

void CircularQueue::enqueue(int value){
	if(isFull()){
		cout<<"Queue is Full. Cannot enqueue!!"<<endl;
		return;
	}else{
		if(front == -1)
			front = 0;
		rear = (rear + 1) % MAX;
		arr[rear] = value;
		cout<<value<<" successfully enqueued!!"<<endl;
	}
}

void CircularQueue::dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to dequeue!!"<<endl;
		return;
	}else{
		int deleted_value = arr[front];
		if(front == rear)	//single element
			front = rear = -1;
		else
			front = (front + 1) % MAX;
		cout<<"successfully deleted "<<deleted_value<<endl;
	}
}

void CircularQueue::print(){
	if(isEmpty()){
		cout<<"Queue is empty. Nothing to print!!"<<endl;
		return;
	}else{
		
		cout<<"Elements of the Queue: "<<endl;
		int i;
		for(i=front;i!=rear;i=(i+1)%MAX)
			cout<<arr[i]<<"  ";
		cout<<arr[i]<<"  END"<<endl;
	}
}

void CircularQueue::printFront(){
	cout<<"Front: "<<front<<endl;
}

void CircularQueue::printRear(){
	cout<<"Rear: "<<rear<<endl;
}

void CircularQueue::debug(){
	cout<<"\n------------------------- DEBUG OUTPUT -------------------------"<<endl;
	(isEmpty())?(cout<<"Empty Queue"):(cout<<"Not an Empty Queue"); cout<<endl;
	(isFull())?(cout<<"Queue is Full"):(cout<<"Queue is not Full"); cout<<endl;
	print();
	printFront();
	printRear();
	cout<<"----------------------------- END ------------------------------"<<endl<<endl;
}

int main(){
	CircularQueue cq1;
	
	cq1.debug();
	
	cq1.enqueue(2);
	
	cq1.debug();
	
	cq1.dequeue();
	
	cq1.debug();
	
	cq1.enqueue(2);
	cq1.enqueue(3);
	
	cq1.debug();
	
	cq1.dequeue();
	
	cq1.debug();
	
	cq1.enqueue(4);
	cq1.enqueue(5);
	cq1.enqueue(6);
	
	cq1.debug();
	
	cq1.enqueue(7);
	
	cq1.debug();
	
	cq1.enqueue(8);
	
	cq1.debug();
	
	cq1.enqueue(9);
	
	cq1.debug();
	
	cq1.dequeue();
	cq1.dequeue();
	cq1.dequeue();
	
	cq1.debug();
	
	cq1.dequeue();
	
	cq1.debug();
	
	cq1.dequeue();
	
	cq1.debug();
	
	return 0;
}
