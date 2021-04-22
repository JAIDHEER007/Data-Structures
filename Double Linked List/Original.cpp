//Using lists container of STL Library for comparision

#include<iostream>
#include<iomanip>
#include<list>
#include<iterator>
#include<cmath>
using namespace std;

string center(int width, int value){
	int len = log10(value);
	if(width < len){ return to_string(value); }
	int diff = width - len;
	int padding1 = diff/2;
	int padding2 = diff - padding1;
	
	return string(padding1,' ') + to_string(value) + string(padding2,' ');
}

void print_dll(list<int> &lst){
	list<int>::iterator itr;
	int count = 0;
	for(itr=lst.begin(); itr!=lst.end(); itr++,count++){
		cout<<"|"<<center(10,(*itr))<<"|";
	}
	cout<<endl;
	for(int s_no = 1; count > 0; s_no++, count--)
		cout<<"|"<<center(10,s_no)<<"|";
	cout<<endl<<endl;
}

int main(){
	list<int> list1;
	
	//push_front_dll function
	list1.push_front(707);
	list1.push_front(553);
	list1.push_front(840);
	
	print_dll(list1);
	
	//push_back_dll function
	list1.push_back(797);
	list1.push_back(770);
	list1.push_back(1200);
	
	print_dll(list1);
	
	//insert_dll function
	//Inserting at first location
	list<int>::iterator itr = list1.begin(); //position 1
	list1.insert(itr,750);
	print_dll(list1);
	
	//Inserting in the middle
	itr = list1.begin();
	itr++;
	itr++;
	itr++;	//position 4;
	/*
		begin()			--> second element  ==> first ++
		second element  --> third element   ==> second ++
		third element   --> fourth element  ==> third ++
	*/
	cout<<"Value: "<<(*itr)<<endl;
	list1.insert(itr,1500);
	
	print_dll(list1);
	
	//Inserting at the end. 
	itr = list1.end();
	itr--;
	
	cout<<(*itr)<<endl;
	list1.insert(itr,807);
	print_dll(list1);
	
	//delete_head_dll function
	list1.pop_front();
	
	print_dll(list1);
	
	//delete_tail_dll function
	list1.pop_back();
	
	print_dll(list1);
	
	//delete_dll function
	//Deleting the first element
	itr = list1.begin();
	list1.erase(itr);
	print_dll(list1);
	
	//Deleting the last element
	itr = list1.end();
	itr--;
	list1.erase(itr);
	print_dll(list1);
	
	//Deleting the random middle element
	itr = list1.begin();
	itr++;
	itr++;	//Position 3
	list1.erase(itr);
	print_dll(list1);
	
	//matched!
	
	return 0;
}
