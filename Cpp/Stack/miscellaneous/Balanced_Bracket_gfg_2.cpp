//Balance Brackets 
//Geeks for Geeks implementation

//accepts characters other than brackets

  
#include<iostream>
#include<stack>
using namespace std;

bool inline openBracket(char ch){
	return ((ch == '(') || (ch == '{') || (ch == '['));
}

bool inline closeBracket(char ch){
	return ((ch == ')') || (ch == '}') || (ch == ']'));
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
			
		if(openBracket(ch) && stk.empty())
			return false;
		
		if(closeBracket(ch) && stk.empty())
			return false;
		
		if(closeBracket(ch)){
			if(isInverse(stk.top(),ch)) 
				stk.pop();
			else
				return false;
		}	
	}
	
	return stk.empty();
}

int main(){
	cout<<boolalpha<<isBalanced("[()]{}{[()()]()}")<<endl;	//true
	cout<<boolalpha<<isBalanced("s.[j(a)i]d{h}e{e[r(0)0(7)5]5(3)}")<<endl;	//true
	cout<<boolalpha<<isBalanced("}[()]{}{[()()]()}")<<endl;	//false
	cout<<boolalpha<<isBalanced("")<<endl; //true
	cout<<boolalpha<<isBalanced("jaidheer")<<endl; //true
	cout<<boolalpha<<isBalanced("[(])")<<endl;	//false
	cout<<boolalpha<<isBalanced("{jaidheer}}")<<endl;	//false
		
	return 0;
}



