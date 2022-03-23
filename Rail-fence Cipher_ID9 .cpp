//FCAI – Programming 1 – 2022 - Assignment 2  
//Program Name:   Rail-fence Cipher_ID9 .cpp
// Last Modification Date: 24/03/2022 
// Author1 and ID and Group: 20210159
// Author2 and ID and Group: 20210234
// Author3 and ID and Group: 20211002
// Teaching Assistant:  
// Purpose:  Encrypt and Decrypt messages using Rail-fence Cipher technique



#include <iostream>
#include <regex>
using namespace std;

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



void encrypt()
{
	string message;
    cout << "Enter message: ";
    getline(cin , message);
    
    message = regex_replace(message, regex("\\s+"), "");  //to remove white spaces from message given

    cout << "Enter depth: ";
    int depth;
    cin >> depth;

	char matrix [depth][message.length()]; //creat empty matrix to hold message elements 
	
	for (int i = 0; i < depth; i++) // replce all places in matrix array with dots
	{
		for (int j = 0; j < message.length(); j++)
		{
			matrix [i][j] = '.';
		}
	}


	int row = 0, change = 0;
	for (int i = 0; i < message.length(); i++)  // putting message letters one by one in rail matrix in zig-zag
	{
		if (change == 0)
		{
			matrix[row][i] = message[i];
			row++;

			if (row == depth)
			{
				change = 1;
				row--;
			}
		}
		else if (change == 1)
		{
			row--;
			matrix[row][i] = message[i];
			if (row == 0)
			{
				change = 0;
				row = 1;
			}
		}
	}
	
	
	string encrypted = "" ; // making and empty string variable to hold the encrypted message
	for (int i = 0 ; i < depth ; i++)
	{
		for(int j = 0 ; j < message.length() ; j++)
		{
			encrypted += matrix[i][j] ;
		}
	}
	encrypted = regex_replace(encrypted , regex("\\.") , "");
	
	cout << "The encrypted text : " << encrypted;
}



void decrypt(){
	cout<< "Enter your encrypted text to decrypt : ";
	string message = "" ;
	getline(cin , message);
	
	cout<< "Enter the depth : ";
	int depth = 0 ;
	cin>> depth ;
	
	message =regex_replace(message , regex("\\s+") , "");  //to remove white spaces from message given
	
	char matrix [depth][message.length()]; //creat empty matrix to hold message elements 
	
	for (int i = 0; i < depth; i++) // replce all places in matrix array with dots
	{
		for (int j = 0; j < message.length(); j++)
		{
			matrix [i][j] = '.';
		}
	}


	int row = 0, change = 0;
	for (int i = 0; i < message.length(); i++)   // putting message letters one by one in rail matrix in zig-zag
	{
		if (change == 0)
		{
			matrix[row][i] = message[i];
			row++;

			if (row == depth)
			{
				change = 1;
				row--;
			}
		}
		else if (change == 1)
		{
			row--;
			matrix[row][i] = message[i];
			if (row == 0)
			{
				change = 0;
				row += 1;
			}
		}
	}
	
	
	int index = 0 ;
	for (int i = 0 ; i < depth ; i++) // adding  letters one by one diagonally
	{
		for(int j = 0 ; j < message.length() ; j++ )
		{
			if (!(matrix[i][j] == '.'))
			{
				matrix[i][j] = message[index];
				index++;
			}
		}
	}
	
	
	row = 0, change = 0; 
	string decrypted = "" ;
	for (int i = 0; i < message.length(); i++)  //  concatenate all characters from matrix in one string
	{
		if (change == 0)
		{
			decrypted += matrix[row][i];
			row++;

			if (row == depth)
			{
				change = 1;
				row--;
			}
		}
		else if (change == 1)
		{
			row--;
			decrypted += matrix[row][i];
			if (row == 0)
			{
				change = 0;
				row = 1;
			}
		}
	}
	
	cout<< "The decrypted text : " << decrypted;
	
}



void run(){  //run the code by recursion technique
	int choice ;
	cout<< "choose one of the following option\n[ 1 ] Encrypt a message\n[ 2 ] decrypt a message\n[ 3 ] Exit\nChoice >>";
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
		return 0 ;
	}