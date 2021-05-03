//My own implementation for checking if brackets are balanced or not
//if the function returns -1, then the input string is balanced
//if not, it will return the index where mismatch has ocurred. 

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

int isBalanced(string txt){
	int txt_length = txt.length();
	if(!txt_length){ return -1; } 
	if(txt_length == 1){
		if(openBracket(txt[0]) || closeBracket(txt[0]))
			return 0;
		else
			return -1;
	}
	
	stack<char> stk;
	if(openBracket(txt[0]))
		stk.push(txt[0]);
	else if(closeBracket(txt[0]))
		return 0;
	
	for(int i=1;txt[i]!='\0';i++){
		if((!stk.empty()) || (i < txt_length)){
			if(openBracket(txt[i])) 
				stk.push(txt[i]);
			else if(closeBracket(txt[i])){
				if(isInverse(stk.top(),txt[i]))
					stk.pop();
				else
					return i;
			}
		}else
			return i;
	}
	
	return (stk.empty())?(-1):(txt_length-1);	
}

int main(){
	
	int index = isBalanced("[j(a)i]{d}{[(h)(e)](e)r}"); 
	if(index == -1)
		cout<<"Given string is balanced"<<endl;
	else
		cout<<"mismatch occured at "<<index<<endl;
	
	// 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23	
	// [  j  (  a  )  i  ]  {  d  }  {   [   (   h   )   (   e   )   ]   (   e   )   r   }
	// ^     ^     ^     ^  ^     ^  ^   ^   ^       ^   ^       ^   ^   ^       ^       ^ 
	// 1     2     2     1  1     1  1   2   3       3   3       3   2   2       2       1   
	// ^	 ^-----^     ^  ^-----^  ^   ^   ^-------^   ^-------^   ^   ^-------^       ^
	// ^-----------------^           ^   ^---------------------------^                   ^
	//				 ^---------------------------------------------------^  
	//Balanced
	
	index = isBalanced("[j(a)i]{d}{[(h)(e)(e)r}"); 
	if(index == -1)
		cout<<"Given string is balanced"<<endl;
	else
		cout<<"mismatch occured at "<<index<<endl;
	
	// 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  
	// [  j  (  a  )  i  ]  {  d  }  {   [   (   h   )   (   e   )   (   e   )   r   }
	// ^     ^     ^     ^  ^     ^  ^   ^   ^       ^   ^       ^   ^   ^   ^       ^ 
	// 1 	 2     2     1  1     1  1   2   3       3   3       3   3       3       X
	// ^     ^-----^     ^  ^-----^  ^   ^   ^-------^   ^-------^   ^-------^       ^
	// ^-----------------^           ^   ^--------------------------------------------
	//				 ^-----------------------------------------------^
	//										 ^--> (Mismtach)   
	//not Balanced

	return 0;
}
