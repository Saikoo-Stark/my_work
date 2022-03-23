//FCAI – Programming 1 – 2022 - Assignment 2  
//Program Name:   Morse Code .cpp
// Last Modification Date: 24/03/2022 
// Author1 and ID and Group: 20210159
// Author2 and ID and Group: 20210234
// Author3 and ID and Group: 20211002
// Teaching Assistant:  
// Purpose:  Encrypt and Decrypt messages using Morse code technique



#include <iostream>
#include <string>
#include <map>
using namespace std ;
map<string , string> code = {   // all values in morse code
{  "0", "-----"},
{  "1", ".----"},
{  "2", "..---"},
{ "3", "...--"},
{  "4", "....-"},
{ "5", "....."},
{  "6", "-...."},
{  "7", "--..."},
{  "8", "---.."},
{  "9", "----."},
{  "a", ".-"},
{  "b", "-..."},
{  "c", "-.-."},
{  "d", "-.."},
{  "e", "."},
{  "f", "..-."},
{  "g", "--."},
{  "h", "...."},
{  "i", ".."},
{  "j", ".---"},
{  "k", "-.-"},
{  "l", ".-.."},
{  "m", "--"},
{  "n", "-."},
{  "o", "---"},
{  "p", ".--."},
{  "q", "--.-"},
{  "r", ".-."},
{  "s", "..."},
{  "t", "-"},
{  "u", "..-"},
{  "v", "...-"},
{  "w", ".--"},
{  "x", "-..-"},
{  "y", "-.--"},
{  "z", "--.."},
{  ".", ".-.-.-"},
{  ",", "--..--"},
{  "?", "..--.."},
{  "!", "-.-.--"},
{  "-", "-....-"},
{  "/", "-..-."},
{  "@", ".--.-."},
{  "(", "-.--."},
{  ")", "-.--.-"}
};

string sepa(char character , int num) //make separetors
{
	string total = "";
	for(int i = 0 ; i < num ; i++)
	total += character;
	
	return total ;
}

bool continued(){      //to ask user if he wanna reuse the code again
	char c;
	cout<< "\n\nare you wanna repeat again?\ntype 'y' to continue : ";
	cin>>c;
	if(c == 'y')
	return true;
	else
	return false;
}



string get_key(map<string , string>mp , string search){  //search about key by its value
	for(auto x = mp.begin() ; x != mp.end() ; x++){
		if (search == x->second)
		return x->first;
	}
	return "";
}


string encrypt(){
	string message  , encrypted = "" , chara;
	cout << "enter message : ";
	getline(cin , message);
	
	for (char x : message){
	chara = tolower(x); // change all chars to lower case 
	if (x == ' ')
	encrypted += "    ";
	else{
	encrypted += code[chara];  //search in map for this char value
	encrypted += " ";
	}
}
return "encrypt of your message : " + encrypted + "\n";
}


string decrypt(){
	string message  , decrypted = "" , chunk = "";
	int space = 0;
	cout << "enter message : ";
	getline(cin , message);
	
	
for(int i = 0 ; i < message.length() ; i++){
	if(message[i] != ' '){
	chunk += message[i];
	if((message.length() == i + 1)){
		decrypted += get_key(code , chunk); 
	}
	space = 0;
	}
	else if (message[i] == ' '){
		decrypted += get_key(code , chunk);
		chunk = "";
		space += 1;
		if(space == 3){
			decrypted += " ";
			space = 0 ;
		}
	}
}

return "decrypt of your message : " + decrypted + "\n";
}


void run(){  //run the code by recursion technique
	int choice ;
	cout<< "choose one of the following option\n[ 1 ] Encrypt a message\n[ 2 ] decrypt a message\n[ 3 ] Exit\nChoice >> ";
	cin>> choice;
	cin.ignore();

	if (choice == 1){
	cout<< sepa('*' , 20)<< endl;
	cout<< encrypt();
	}
	else if (choice == 2){
	cout<< sepa('*' , 20)<< endl;
	cout<< decrypt();
	}
	else if (choice == 3)
	{
	cout<< "\nThanks for using....\nBYE";
	exit(0);
	}
	else{
	cout<<"Error : you have entered an invalid input";
		exit(0);
	}
	if (continued()){
	cout<< "\n" << sepa('*' , 20)<< "\n";
	run();
	}
}



int main(){

cout<< "       >> Hello User <<\n\n";
		run();

}