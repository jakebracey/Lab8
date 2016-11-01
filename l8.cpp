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

MSG::MSG()
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

mcMSG::mcMSG(string x)
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
};

void MSG::printInfo()
{
	cout << msg << endl;
}

void mcMSG::printmcInfo(){
	int i=0;

	if(index>26)
	{
		return;
	}

	for(i=0; i<index; i++)
	{
		cout << tran_msg[i] << " ";
	}
	cout << endl;
}

void mcMSG::translate(){
	string letters="abcdefghijklmnopqrstuvwxyz";
	string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
		   "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
		   "..-","...-",".--","-..-","-.--","--.."};
	int i=0;
	int j=0;
	string c;
	char u;

	index = msg.length();

	if(index>26)
	{
		cout << "Message is too long" << endl;
		return;
	}

	for(i=0; i<index; i++)
	{
		if(isupper(msg[i]))
		{
			u=msg[i];
			msg[i]=tolower(u);
		}

		for(j=0; j<26; j++){
			if(msg[i]==letters[j])
			{
				c=morseCode[j];
				//cout << c << endl;
				tran_msg[i]=c;
			}
		}
	}
}

void MSGSt::push(MSG obj){
	ptrSt[st_top_ptr]=new MSG(obj);
	st_top_ptr++;
}

void MSGSt::pop(){
	delete ptrSt[st_top_ptr];
	st_top_ptr--;

}


int main(void){
	//put these into the translate function
	//mcMSG mcmessage;
	string str;
	cout << "Enter a word to convert to morse (fewer than 20 characters): ";
	cin >> str;
	mcMSG mcmessage(str);
	mcmessage.printInfo();
	mcmessage.translate();
	mcmessage.printmcInfo();
	return 0;
}
