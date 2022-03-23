//FCAI – Programming 1 – 2022 - Assignment 2  
//Program Name:   XOR Cipher.cpp
// Last Modification Date: 24/03/2022 
// Author1 and ID and Group: 20210159
// Author2 and ID and Group: 20210234
// Author3 and ID and Group: 20211002
// Teaching Assistant:  
// Purpose:  Encrypt and Decrypt messages using XOR Cipher technique


#include <iostream>
#include <string>
#include<algorithm>
using namespace std ;

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

string HToS(string n) { 
string message ;
string x ;
for(int i = 0 ; i < n.size() ; i += 2){
	x = n.substr(i , 2);
	char _char = stoi(x , 0 , 16);
	message  += _char;
}
return message ;
}

void encrypt(string message , char key){
      string new_message = "";
      int all;
      cout << "\nHex of message : ";
       for(char ch : message)
       {
       	all =  int(key) ^ int(ch);
       	cout << hex << all;
       	new_message += char(all);
       }
       cout<< endl;
       cout<< "text of message : " << new_message;
}

void decrypt( int entry){
	
	
	if (entry == 1){
		string message ;
		char key;
		cout<< sepa('-' , 20);
		cout<<"\nEnter message : ";
		cin.ignore();
		getline(cin , message);
		cout<< "Enter key : ";
		cin>> key ;
		encrypt(message , key);
		
	}
	
	else if (entry == 2){
		string message ;
		char key;
		cout<< sepa('-' , 20);
		cout<<"\nEnter message : ";
		cin.ignore();
		getline(cin , message);
		cout<< "Enter key : ";
		cin>> key ;
		string new_message = HToS(message);
		encrypt(new_message , key);
	}
	
	else{
	
	cout<< "\nThanks for using me...";
	exit(0);
	}
}

void run(){
	
	int option ;
	
	cout<< "\nChoose one of the following options:\n[ 1 ] Encryption\n[ 2 ] Decryption\nChoice: ";
	cin >> option;
	
	if (option == 1){
		string message ;
		char key;
		cout<< sepa('-' , 20);
		cout<<"\nEnter message : ";
		cin.ignore();
		getline(cin , message);
		cout<< "Enter key : ";
		cin>> key ;
		encrypt(message , key);
		
	}
	else if (option == 2){
	cout<<  sepa('-' , 30);
	int entry;
	cout<< sepa('-' , 20) << "\nChoose entry method : \n[ 1 ] Text method\n[ 2 ] HexaDecimal method \nChoice : ";
	cin>> entry ;

	decrypt(entry);
	
	}
	
	else{
	cout<< "\nThanks for using me...";
	exit(0);
	}
	
	
	if(continued()){
	cout<< "\n" << sepa('-' , 20);
	run();
	}
	else{
	cout<< "\nThanks for using me...";
	exit(0);
	}
}



int main(){
	cout<<"   >> Hello User <<";
	run();
	
}