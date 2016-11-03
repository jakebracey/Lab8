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
		string mes;
		
	public:
		MSG();
		MSG(string);
		~MSG();
		virtual void printInfo();
};

MSG::~MSG(){
//no memory allocated so there is nothing to delete here
}

MSG::MSG(){ //default constructor

}

MSG::MSG(string x){
	mes=x;
}
void MSG::printInfo(){ //prints message
	cout << "Message: " << mes << endl;
}

class mcMSG : public MSG{
	public:
		string *tran_msg;
		int index;
		void printInfo();
		void translate();
		mcMSG();
		mcMSG(string);
		~mcMSG();
};

mcMSG::mcMSG(){ //default constructor
cout<<"Default mcMSG constructor called\nEnter a word:";
cin>>mes;
translate();
}

mcMSG::mcMSG(string y){ //constructs message
	mes=y;
	
	//sends the string to be translated to morse code
	translate();
}

mcMSG::~mcMSG(){
	//deconstructor to delete the allocated memory
	delete[] tran_msg;
}

void mcMSG::printInfo(){ //prints morse
	int i=0;
/*
	if(index>26) //prevents seg fault
	{
		return;
	}
*/
	cout<<"Text: "<<mes<<endl;
	cout << "Morse: ";
	for(i=0; i<index; i++) //prints each letter in morse
	{
		cout << tran_msg[i] << " ";
	}
	cout << endl;
}

void mcMSG::translate(){
	string letters="abcdefghijklmnopqrstuvwxyz"; //defining alphabet and morse code
	string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	int i=0;
	int j=0;
	string c;
	char u;

	index = mes.length(); //gets length of string
	tran_msg=new string[index];

	for(i=0; i<index; i++)
	{
		if(isupper(mes[i])) //changes uppercase letters to lowercase
		{
			u=mes[i];
			mes[i]=tolower(u);
		}

		for(j=0; j<26; j++){ //translates message into morse
			if(mes[i]==letters[j])
			{
				c=morseCode[j];
				tran_msg[i]=c;
			}
		}
	}
}

class MSGSt{
	public:
		MSG *ptrSt[10];
		int st_top_ptr;
		int num_obj;
		
		void push(MSG obj);
		void push(mcMSG obj);
		void pop();
		void printStack();
		MSGSt();
};

MSGSt::MSGSt(){
	st_top_ptr=0;
	num_obj=0;
}

void MSGSt::printStack(){
	int i=0;
	for(i=0; i<num_obj; i++){ //prints each string on the stack
		ptrSt[st_top_ptr-i-1]->printInfo();
	}
	cout << endl;

}

void MSGSt::push(MSG obj){ //pushes word to stack
	ptrSt[st_top_ptr]=new MSG(obj);
	st_top_ptr++;
	num_obj++;
}

void MSGSt::push(mcMSG obj){ //pushes word to stack
	ptrSt[st_top_ptr]=new mcMSG(obj);
	st_top_ptr++;
	num_obj++;
}

void MSGSt::pop(){ //pops word from stack
	st_top_ptr--;
	delete ptrSt[st_top_ptr];
	num_obj--;
}

int main(void){
	MSGSt stackmsgs;
	
	//gets a string from the user
	string str,str2;
	cout << "Enter a word to convert to morse code: "; //takes in word to convert
	cin >> str;
	
	//puts str into the morse code message class
	mcMSG m1(str);
	m1.printInfo();//prints out data
	stackmsgs.push(m1);//pushes this onto the stack
	
	
	//gets another string from the user
	cout <<endl<< "Enter another word to store in the message class: "; //takes in word to convert
	cin >> str2;
	
	//puts that into the message class
	MSG m2(str2);
	m2.printInfo();//prints out data	
	stackmsgs.push(m2);
	
	
	cout<<endl<<"Printing out the stack\n";
	stackmsgs.printStack();
	stackmsgs.pop();	
	
	
	
	
	//stackmsgs.pop();
	m1.printInfo();
	
	return 0;
}
