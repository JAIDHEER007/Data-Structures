// Implementing prefix tree (trie) using structures

#include<iostream>
#define A_SIZE 26
using namespace std; 

struct node{
    node* children[A_SIZE];
    bool isEnd; 
};
typedef node node; 

node* getNode(){
    node* newNode = new node();
    newNode->isEnd = false; 
    for(int i = 0; i < A_SIZE; ++i) newNode->children[i] = NULL;
    return newNode; 
}

void insert(node* root, string txt){
    node* curr = root; 
    for(char ch:txt){
        int index = ch - 'a';
        if(curr->children[index] == NULL)
            curr->children[index] = getNode(); 
        curr = curr->children[index]; 
    }
    curr->isEnd = true;  
}

bool search(node* root, string key){
    node* curr = root; 
    for(char ch:key){
        int index = ch - 'a'; 
        if(curr->children[index] == NULL) return false; 
        curr = curr->children[index]; 
    }
    return curr->isEnd; 
}

bool startsWith(node* root, string key){
    node* curr = root; 
    for(char ch:key){
        int index = ch - 'a'; 
        if(curr->children[index] == NULL) return false; 
        curr = curr->children[index]; 
    }
    return true; 
}

int main(){

    node* root = getNode(); 

    cout<<"Root Address: "<<root<<endl; 
    cout<<boolalpha<<root->isEnd<<endl; 
    
    insert(root, "jaidheer"); 
    insert(root, "jaiveer"); 

    cout<<boolalpha<<search(root, "jai")<<endl;
    cout<<boolalpha<<startsWith(root, "jai")<<endl;
    
    return 0; 
}

