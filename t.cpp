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