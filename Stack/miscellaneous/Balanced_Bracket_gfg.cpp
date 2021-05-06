//Balance Brackets 
//Geeks for Geeks implementation

//Doesnot accept characters other than brackets
//Much simpler with less helper functions
  
#include<iostream>
#include<stack>
using namespace std;

bool inline openBracket(char ch){
	return ((ch == '(') || (ch == '{') || (ch == '['));
}

bool isInverse(char stk_top, char closedBracket){
	if(stk_top == '('){ return closedBracket == ')'; }
	if(stk_top == '{'){ return closedBracket == '}'; }
	if(stk_top == '['){ return closedBracket == ']'; }
}

bool isBalanced(string expression){
	stack<char> stk;
	for(char ch:expression){
		if(openBracket(ch)){
			stk.push(ch);
			continue;
		}
			
		if(stk.empty())
			return false;
			
		if(isInverse(stk.top(),ch))
			stk.pop();
		else
			return false;
	}
	
	return stk.empty();
}

int main(){
	cout<<boolalpha<<isBalanced("[()]{}{[()()]()}")<<endl;	//True
	cout<<boolalpha<<isBalanced("[()]{j}{[()()]()}")<<endl;	//False
	cout<<boolalpha<<isBalanced("[(])")<<endl;	//False
	
	return 0;
}

