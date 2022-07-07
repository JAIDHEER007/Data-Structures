//Linked List using class

#include<iostream>
#include<vector>
#include<iomanip>
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
		node *next;
		
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

class SLinkedList : protected node{
	private:
		node *head, *tail;
	public:
		SLinkedList(){
			head = tail = NULL;
		}
		
		void push_front_sll(int val);
		void push_back_sll(int val);
		void insert_sll(int val, int position);
		void push_front_sll(vector<int> &input_arr);
		void push_back_sll(vector<int> &input_arr);
		
		void delete_front_sll();
		void delete_back_sll();
		void delete_sll(int position);
		
		bool isSorted();
		void insert_sorted_sll(int val);
		
		int length_sll();
		void print_sll_debug();
};

void SLinkedList::push_front_sll(int val){
	node *temp = new node(val);
	if(head == NULL)
		head = tail = temp;
	else{
		temp -> next = head;
		head = temp;
	}
}

void SLinkedList::push_back_sll(int val){
	node *temp = new node(val);
	if(tail == NULL)
		head = tail = temp; 
	else{
		tail -> next = temp;
		tail = temp;
	}
}

void SLinkedList::insert_sll(int val, int position){
	node *temp = new node(val);
	
	if((position < 1) || (position > length_sll())){
		cout<<"Cannot insert node outside the Linked List"<<endl;
		return;
	}else if(position == 1){
		temp->next = head;
		head = temp;
	}else{
		node *curr = head;
		int curr_position = 1;
		while(curr_position < (position - 1)){
			curr = curr -> next;
			curr_position++;
		}
		temp -> next = curr -> next;
		curr -> next = temp;
	}
}

void SLinkedList::push_front_sll(vector<int> &input_arr){
	if(!input_arr.size()){
		cout<<"Provide an input array with elements"<<endl;
		return;
	}
	for(int input_element:input_arr)
		push_front_sll(input_element);
}

void SLinkedList::push_back_sll(vector<int> &input_arr){
	if(!input_arr.size()){
		cout<<"Provide an input array with elements"<<endl;
		return;
	}
	for(int input_element:input_arr)
		push_back_sll(input_element);
}

void SLinkedList::delete_front_sll(){
	node *temp = head;
	if((head == tail) && (head != NULL)){
		tail = head = NULL;
		delete(temp);
	}else if(head != NULL){
		head = head -> next;
		delete(temp);
	}else
		cout<<"List is empty! Nothing to Delete.."<<endl;
}

void SLinkedList::delete_back_sll(){
	node *temp = tail;
	if((head == tail) && (tail != NULL)){
		head = tail = tail -> next;
		delete(temp);
	}else if(tail != NULL){
		node *curr = head;
		while(curr->next!=temp)
			curr = curr->next;
		curr->next = NULL;
		tail = curr;
		delete(temp);
	}else
		cout<<"List is empty! Nothing to delete.."<<endl;
}

void SLinkedList::delete_sll(int position){
	if((position < 1) || (position > length_sll())){
		cout<<"Cannot delete outside the Linked List"<<endl;
		return;
	}
	else if(position == 1)
		delete_front_sll();
	else if(position == length_sll())
		delete_back_sll();
	else{
		int curr_position = 1;
		node *curr = head;
		while(curr_position < (position - 1)){
			curr = curr -> next;
			curr_position++;
		}
		node *next_node = curr -> next;
		curr -> next = next_node -> next;
		delete(next_node);
	}
}

bool SLinkedList::isSorted(){
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

void SLinkedList::insert_sorted_sll(int val){
	if(head == NULL)
		push_front_sll(val);
	else if(isSorted()){
		if(((head->data > val) && (tail->data < val))||((head->data < val) && (tail->data > val))){
			node *temp = head;
			bool toggle = !((temp->data) < val);
			while((((temp->next)->data) < val) ^ toggle)
				temp = temp->next;
			node *new_node = new node(val);
			new_node -> next = temp -> next;
			temp -> next = new_node;
		}else{
			if((head->data) <= (tail->data)){
				if(val <= (head->data))
					push_front_sll(val);
				else
					push_back_sll(val);
			}else{
				if(val >= (head->data))
					push_front_sll(val);
				else
					push_back_sll(val);
			}
		}
	}
}

int SLinkedList::length_sll(){
	int len = 0;
	node *temp = head;
	while(temp!=NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}

void SLinkedList::print_sll_debug(){
	if(head == NULL){
		cout<<"Single Linked List is empty. Nothing to print!!"<<endl;
		return;
	}
	int s_no = 1;
	node *temp = head;
	
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
	SLinkedList sll1;
	
	sll1.print_sll_debug();
	
	vector<int> input_arr{ 405, 95, 203, 195, 32,
			       8, 387, 43, 19, 493,
			       26, 389, 357, 320, 265,
			       75, 388, 378, 136, 375 }; 

	sll1.push_back_sll(input_arr);
	
	sll1.print_sll_debug();
	
	sll1.delete_front_sll();
	
	sll1.print_sll_debug();
	
	sll1.delete_back_sll();
	
	sll1.print_sll_debug();
	
	sll1.insert_sll(143,0);
	sll1.insert_sll(143,100);
	
	sll1.insert_sll(143,1);
	
	sll1.print_sll_debug();
	
	sll1.insert_sll(707,19);
	
	sll1.print_sll_debug();
	
	sll1.insert_sll(840,9);
	
	sll1.print_sll_debug();
	
	sll1.delete_sll(0);
	sll1.delete_sll(100);
	
	sll1.delete_sll(1);
	
	sll1.print_sll_debug();
	
	sll1.delete_sll(20);
	
	sll1.print_sll_debug();
	
	sll1.delete_sll(9);
	
	sll1.print_sll_debug();
	
	cout<<boolalpha<<sll1.isSorted()<<endl;
	
	SLinkedList sll2;
	
	vector<int> input_arr2{8, 9, 15, 38, 58,
			       82, 118, 158, 214, 230,
			       256, 280, 293, 315, 336,
			       343, 359, 441, 457, 491 };
						   
	sll2.push_back_sll(input_arr2);					   
						   
	sll2.print_sll_debug();
	
	cout<<boolalpha<<sll2.isSorted()<<endl;
	
	sll2.insert_sorted_sll(5);
	
	sll2.print_sll_debug();
	
	sll2.insert_sorted_sll(500);
	
	sll2.print_sll_debug();
	
	sll2.insert_sorted_sll(300);
	
	sll2.print_sll_debug();
	
	return 0;
}
