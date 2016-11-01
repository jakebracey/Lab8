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


using namespace std;

class MSG{
	protected:
		string msg;
		
	public:
		MSG();
		MSG(string);
		~MSG();
		virtual void printInfo();
};

class mcMSG : public MSG{
	public:
		string * tran_msg;
		int index;
		void printInfo();
		void translate();
	
};

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
	string letters="abcdefghijklmnopqrstuvwxyz"
	string morseCode[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
	       "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
	       "..-","...-",".--","-..-","-.--","--.."};
}