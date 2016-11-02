/*
 ============================================================================
 Name        : L8.cpp
 Author      : Jacob Bracey
 Description : ECE 3220: Lab 7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class MSG{
	protected:
		string msg;
		
	public:
		MSG();
		MSG(string);
		~MSG();
		void printInfo();
};

MSG::~MSG(){
}

MSG::MSG() //default constructor
{
	msg="heLLo";
}

MSG::MSG(string x)
{
	msg=x;
}

class mcMSG : public MSG{
	public:
		string tran_msg[26];
		int index;
		void printmcInfo();
		void translate();
		mcMSG(string);
};

mcMSG::mcMSG(string x) //constructs message
{
	msg=x;
}

class MSGSt{
	public:
		MSG *ptrSt[10];
		int st_top_ptr;
		int num_obj;
		//may need more
		
		void push(MSG obj);
		void pop();
		void printStack();
		MSGSt();
};

MSGSt::MSGSt(){
	st_top_ptr=0;
	num_obj=0;
}


void MSG::printInfo() //prints message
{
	cout << "Message: " << msg << endl;
}

void mcMSG::printmcInfo(){ //prints morse
	int i=0;

	if(index>26) //prevents seg fault
	{
		return;
	}

	cout << "Morse: ";
	for(i=0; i<index; i++) //prints each letter in morse
	{
		cout << tran_msg[i] << " ";
	}
	cout << endl;
}

void mcMSG::translate(){
	string letters="abcdefghijklmnopqrstuvwxyz"; //defining alphabet and morse code
	string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
		   "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
		   "..-","...-",".--","-..-","-.--","--.."};
	int i=0;
	int j=0;
	string c;
	char u;

	index = msg.length(); //gets length of string

	if(index>26) //prevents seg faults by limiting length of input message
	{
		cout << "Message is too long" << endl;
		return;
	}

	for(i=0; i<index; i++)
	{
		if(isupper(msg[i])) //changes uppercase letters to lowercase
		{
			u=msg[i];
			msg[i]=tolower(u);
		}

		for(j=0; j<26; j++){ //translates message into morse
			if(msg[i]==letters[j])
			{
				c=morseCode[j];
				tran_msg[i]=c;
			}
		}
	}
}

void MSGSt::printStack(){
	int i=0;
	for(i=0; i<num_obj; i++) //prints each string on the stack
	{
		ptrSt[st_top_ptr-i-1]->printInfo();
	}
	cout << endl;

}

void MSGSt::push(MSG obj){ //pushes word to stack
	ptrSt[st_top_ptr]=new MSG(obj);
	st_top_ptr++;
	num_obj++;
}

void MSGSt::pop(){ //pops word from stack
	st_top_ptr--;
	delete ptrSt[st_top_ptr];
	num_obj--;
}

int main(void){
	int input=0;
	int max=10;
	int num=0;
	MSGSt stackmsgs;
	string str;
	cout << "Enter a word to convert to morse (fewer than 20 characters): "; //takes in word to convert
	cin >> str;
	mcMSG mcmessage(str);
	mcmessage.printInfo(); //prints word
	mcmessage.translate(); //translates to morse
	mcmessage.printmcInfo(); //prints word in morse
	cout<<endl<<endl;
	while(input!=4) //menu
	{
		cout << "1:Push word to stack"<<endl<<"2:Pop word"<<endl<<"3:Print Stack"<<endl<<"4:Stop"<<endl; //takes in operation
		cin >> input;
		while(input<1 || input>4){
			cout << "1:Push word to stack"<<endl<<"2:Pop word"<<endl<<"3:Print Stack"<<endl<<"4:Stop"<<endl;
			cin >> input;
		}
		cout<<endl;
		if(input==1){
			if(num<max){ //pushes new word to stack
				cout << "Enter a word to put on stack: ";
				cin >> str;
				MSG one(str);
				stackmsgs.push(one);
				num++;
			}
			else{
				cout<<"Can't add any more messages to stack"<<endl; //ensures no seg fault
			}
		}
		if(input==2){ //pops word from stack
			if(stackmsgs.num_obj<1){
				cout<<"Nothing to pop"<< endl;
			}
			else{
				stackmsgs.pop();
				num--;
			}
		}
		if(input==3){ //prints stack
			stackmsgs.printStack();
		}
	}

	return 0;
}
