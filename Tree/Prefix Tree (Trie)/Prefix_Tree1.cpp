//Prefix Tree implementation (Trie)

#include<iostream>
#include<queue>
#include<sstream>
#define A_SIZE 26

using namespace std;

string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff / 2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

void printStringStream(int width, stringstream &ss){
    cout<<"+"<<center(width, ss.str())<<"+"<<endl; 
    ss.str("");
}

class node{
    public:
        node *children[A_SIZE] = { NULL };
        bool isEnd;

        node(){
            this->isEnd = false; 
        }
}; 

class prefixTree : protected node{
    private:
        node *root;
    public:
        prefixTree(){
            root = new node();
        }
    
        void insert(string txt){
            node *curr = root;
            for(char ch:txt){
                int index = ch - 'a'; 
                if(curr->children[index] == NULL)
                    curr->children[index] = new node(); 
                curr = curr->children[index]; 
            }
            curr->isEnd = true; 
        }

        bool search(string key){
            node *curr = root; 
            for(char ch:key){
                int index = ch - 'a'; 
                if(curr->children[index] == NULL) return false; 
                curr = curr->children[index]; 
            }
            return curr->isEnd; 
        }

        bool startsWith(string prefix){
            node *curr = root; 
            for(char ch:prefix){
                int index = ch - 'a'; 
                if(curr->children[index] == NULL) return false; 
                curr = curr->children[index]; 
            }
            return true; 
        }

        // Debugging function 
        // Prints contents of every node in Level Order
        void printTree(){
            queue<node*> q; 
            stringstream ss; 
            ss.str("");  

            q.push(root); 
            int nodeCount = 0; 
            while(!q.empty()){
                node *curr = q.front(); 
                q.pop(); 

                cout<<"++++++++++++++++++++++++++++++++++"<<endl; 
                
                ss<<"Node Number: "<<(nodeCount++);
                printStringStream(32, ss); 
                 
                ss<<"Is Ending Node: "<<boolalpha<<(curr->isEnd);
                printStringStream(32, ss);
                               
                ss<<"Address: "<<curr;
                printStringStream(32, ss);
                               
                cout<<"+++++++++++  Children  +++++++++++"<<endl;
                for(int i = 0; i < A_SIZE; ++i){
                    ss<<char('a' + i)<<": "<<(curr->children[i]);
                    printStringStream(32, ss); 
                                   
                    if(curr->children[i] != NULL) q.push(curr->children[i]); 
                }
                cout<<"++++++++++++++++++++++++++++++++++"<<endl;
            }
        }
};


int main(){
    
    prefixTree pt1; 

    pt1.insert("edu");

    pt1.insert("education");
    pt1.insert("educative");
    pt1.insert("educator");

    cout<<boolalpha<<pt1.startsWith("edu")<<endl; 

    return 0; 
}
