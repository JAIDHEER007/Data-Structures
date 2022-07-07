//Double Linked Lists

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

string inline tf(bool tf){
	return (tf?"True":"False"); 
}

class node{
	public:
		int data;
		node *next;
		node *prev;
			
		node(){
			data = 0;
			next = prev = NULL;
		}
		node(int val){
			data = val;
			next = prev = NULL;
		}
};

class DLinkedList : protected node{
	private:
		node *head, *tail;
	public:
		DLinkedList(){
			head = tail = NULL; 
		}
		
		void push_front_dll(int val);
		void push_back_dll(int val);
		void insert_dll(int value, int position);
		void push_front_dll(vector<int> &input_arr);
		void push_back_dll(vector<int> &input_arr);
		
		void delete_head_dll();
		void delete_tail_dll();
		void delete_dll(int position);
		
		int length_dll();
		void print_dll();
		void print_dll_reverse();
		
		bool isSorted();
		void insert_sorted_dll(int val);
		
		void print_dll_debug();
};

void DLinkedList::push_front_dll(int val){
	node *temp = new node(val);
	if(head == NULL)
		head = tail = temp;
	else{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void DLinkedList::push_back_dll(int val){
	node *temp = new node(val);
	if(head == NULL)
		head = tail = temp;
	else{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

void DLinkedList::insert_dll(int value, int position){
	node *temp = new node(value);
	if((position < 1) || (position > length_dll())){
		cout<<"Cannot Insert Node outside of the Linked List"<<endl;
		delete(temp);
		return;
	}else if(position == 1){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}else{
		node *curr = head;
		int curr_position = 1;
		while(curr_position < (position-1)){
			curr = curr->next;
			curr_position++;
		}
		temp->next = curr->next;
		(curr->next)->prev = temp;
		curr->next = temp;
		temp->prev = curr;
	}
}

void DLinkedList::push_front_dll(vector<int> &input_arr){
	if(!input_arr.size()){
		cout<<"Provide an input array with elements"<<endl;
		return;
	}
	for(int input_element:input_arr)
		push_front_dll(input_element);
}

void DLinkedList::push_back_dll(vector<int> &input_arr){
	if(!input_arr.size()){
		cout<<"Provide an input array with elements"<<endl;
		return;
	}
	for(int input_element:input_arr)
		push_back_dll(input_element);
}

void DLinkedList::delete_head_dll(){
	node *temp = head;
	if((head == tail) && (head != NULL)){
		head = tail = NULL;
		delete(temp);
	}else if(head != NULL){
		(head->next)->prev = NULL;
		head = head->next;
		delete(temp);
	}else
		cout<<"List is empty. Nothing to delete!!"<<endl;
}

void DLinkedList::delete_tail_dll(){
	node *temp = tail;
	if((head==tail) && (tail != NULL)){
		head = tail = NULL;
		delete(tail);
	}else if(tail != NULL){
		(tail->prev)->next = NULL;
		tail = tail->prev;
		delete(temp);
	}else
		cout<<"List is empty. Nothing to delete!!"<<endl;
}

void DLinkedList::delete_dll(int position){
	if((position < 1) || (position > length_dll())){
		cout<<"Cannot delete outside the Linked List"<<endl;
		return;
	}else if(position == 1)
		delete_head_dll();
	else if(position == length_dll())
		delete_tail_dll();
	else{
		int curr_position = 1;
		node *present_node = head;
		while(curr_position < (position - 1)){
			present_node = present_node -> next;
			curr_position++;
		}
		present_node->next = (present_node->next)->next;
		delete((present_node->next)->prev);
		(present_node->next)->prev = present_node;
	}
}

int DLinkedList::length_dll(){
	int len = 0;
	node *temp = head;
	while(temp != NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}

void DLinkedList::print_dll(){
	if(head == NULL){
		cout<<"Double Linked List is empty. Nothing to print!!"<<endl;
		return;
	}
	node *temp = head;
	while(temp != NULL){
		cout<<(temp->data)<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void DLinkedList::print_dll_reverse(){
	if(tail == NULL){
		cout<<"Double Linked List is empty. Nothing to print!!"<<endl;
		return;
	}
	node *temp = tail;
	while(temp != NULL){
		cout<<(temp->data)<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}

bool DLinkedList::isSorted(){
	if(head == NULL)
		return false;
	else{
		bool increasing = true, decreasing = true;
		int temp = head->data;
		node *temp_node = head->next;
		while(temp_node != NULL){
			if(temp < (temp_node->data)){
				increasing = increasing && true; 
				decreasing = decreasing && false;
			}else if(temp > (temp_node->data)){
				increasing = increasing && false; 
				decreasing = decreasing && true;
			}
			temp = temp_node->data;
			temp_node = temp_node -> next;
		}
		return increasing || decreasing; 
	}
}

void DLinkedList::insert_sorted_dll(int val){
	if(head == NULL){
		push_front_dll(val);
	}else if(isSorted()){
		if(((head->data > val) && (tail->data < val))||((head->data < val) && (tail->data > val))){
			node *temp = head;
			bool toggle = !((temp->data) < val);
			while(((temp->data) < val) ^ toggle)
				temp = temp->next;
			node *new_node = new node(val);
			new_node->next = temp;
			new_node->prev = temp->prev;
			(temp->prev)->next = new_node;
			temp->prev = new_node;
		}else{
			if((head->data) <= (tail->data)){
				if(val <= (head->data))
					push_front_dll(val);
				else
					push_back_dll(val);
			}else{
				if(val >= (head->data))
					push_front_dll(val);
				else
					push_back_dll(val);
			}
		}
	}else
		cout<<"Given Double Linked List is not Sorted. Cannot Insert the element!!"<<endl;
}

void DLinkedList::print_dll_debug(){
	if(head == NULL){
		cout<<"Double Linked List is empty. Nothing to print!!"<<endl;
		return;
	}
	int s_no = 1;
	node *temp = head;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<setw(10)<<left<<"Node_No"<<setw(20)<<left<<"Address"<<setw(20)<<left<<"Next"<<setw(20)<<left<<"Prev"<<"Data"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	while(temp != NULL){
		cout<<setw(10)<<left<<s_no<<setw(20)<<left<<temp<<setw(20)<<left<<temp->next<<setw(20)<<left<<temp->prev<<temp->data<<endl;
		temp = temp -> next;
		s_no++;
	}
	cout<<"--------------------------------------------------------------------------"<<endl;
}

int main(){
	DLinkedList dll1;
	
	vector<int> input_arr{ 950, 931, 387, 706, 634, 
			       849, 514, 599, 265, 232, 
			       652, 650, 513, 947, 854, 
			       370, 996, 200, 539, 769 };
					
	dll1.push_back_dll(input_arr);	  
	dll1.print_dll_debug();
	
	cout<<tf(dll1.isSorted())<<endl;
	
	dll1.insert_sorted_dll(553);
	
	DLinkedList dll2;
	
	vector<int> input_arr2{ 78,84,190,325,340,446,458 };
	
	dll2.push_front_dll(input_arr2);
	
	dll2.print_dll_debug();
	
	dll2.insert_sorted_dll(200);
	dll2.insert_sorted_dll(447);
	
	dll2.print_dll_debug();
	
	dll2.insert_sorted_dll(70);
	dll2.insert_sorted_dll(460);
	
	dll2.print_dll_debug();
	return 0;
}
