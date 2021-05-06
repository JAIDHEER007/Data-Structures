//Printing the maximum element from the stack

//We have to print maximum element in the stack on request 

//We have to preserve the LIFO order even when finding the largest element

#include<iostream>
#include<stack>

using namespace std;

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
	stack<int> elementStack, maxStack;
	
	cout<<">>>MENU<<<"<<endl;
	cout<<"1. Push element"<<endl;
	cout<<"2. Pop element"<<endl;
	cout<<"3. Print Maximum"<<endl;
	cout<<"4. Print stack"<<endl;
	cout<<"5. exit"<<endl<<endl;
	
	int opt, val;
	
	while(true){
		cout<<"Enter your option: ";
		cin>>opt;
		
		switch(opt){
			case 1:{
				cout<<"Enter element: ";
				cin>>val; 
				
				elementStack.push(val);
				if(maxStack.empty()){ maxStack.push(val); }
				else
					if(maxStack.top() <= val){ maxStack.push(val); }
					cout<<"pushed "<<val<<" into stack"<<endl;
				
				break;
			}
			case 2:{
				int del = elementStack.top();
				elementStack.pop();
				if(del == maxStack.top()){ maxStack.pop(); }
				cout<<"Popped"<<endl;
				
				break;	
			}
			case 3:{
				cout<<"Max element in the stack: "<<maxStack.top()<<endl;
				break;
			}
			case 4:{
				print_Up_to_Bottom(elementStack);
				cout<<"END"<<endl;
				break;
			}
			case 5: return 0;
			default: cout<<"Invalid Choice"<<endl;
		}
	}
	return 0;
}
