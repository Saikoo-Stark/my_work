//FCAI – Programming 1 – 2022 - Assignment 2  
//Program Name:   Polybius Square Cipher .cpp
// Last Modification Date: 24/03/2022 
// Author1 and ID and Group: 20210159
// Author2 and ID and Group: 20210234
// Author3 and ID and Group: 20211002
// Teaching Assistant:  
// Purpose:  Encrypt and Decrypt messages using Polybius Square Cipher technique



#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> code;


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

void store(string key) // to store all alphas as a value of key coming from user
{
	string  keym, value;
	int start = 65;

	for (int s1 = 0; s1 < key.length(); s1++)
	{
		for (int s2 = 0; s2 < key.length(); s2++)
		{
			keym = char(start); // get the uppercase alphas
			value = key[s1];
			value += key[s2];
			code.insert({keym, value});

			start += 1;

			if (s1 == 1 && s2 == 3) //condtion of two alphas ( I , J ) with same value
			{
				value = key[s1];
				value += key[s2];

				keym = char(start);
				code.insert({keym, value});

				start += 1;
			}
		}
	}
}

void encrypt(){ // encrypt the message from user
	string message, key , con , encrypted = "";
	cout<< "Enter message to encrypt : ";
	getline(cin , message);
	cout<< "Enter key of 5 numbers : " ;
	getline(cin ,key);
	store(key);
	for (char chara : message ){
		con = toupper(chara) ;
		encrypted +=  code[con];
	}
	cout<< encrypted;
}

void decrypt(){
	string message, key , con , decrypted = "";
	cout<< "Enter message to decrypt : ";
	getline(cin , message);
	cout<< "Enter key of 5 numbers : " ;
	getline(cin ,key);
	store(key);
	for (int i =0 ; i < message.length(); i += 2){
		con = message[i] ;
		con += message[i+1]  ;
		decrypted +=  get_key(code , con); // searching about key by its value
	}
	cout<< decrypted;
}

void run(){  //run the code by recursion technique
	int choice ;
	cout<< "choose one of the following option\n[ 1 ] Encrypt a message\n[ 2 ] decrypt a message\n[ 3 ] Exit\nChoice >> ";
	cin>> choice;
	cin.ignore();

	if (choice == 1){
	cout<< sepa('*' , 20)<< endl;
	encrypt();
	}
	else if (choice == 2){
	cout<< sepa('*' , 20)<< endl;
	decrypt();
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