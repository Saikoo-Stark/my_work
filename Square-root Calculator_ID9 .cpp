//FCAI – Programming 1 – 2022 - Assignment 2  
//Program Name:   Square-root Calculator_ID9 .cpp
// Last Modification Date: 24/03/2022 
// Author1 and ID and Group: 20210159
// Author2 and ID and Group: 20210234
// Author3 and ID and Group: 20211002
// Teaching Assistant:  
// Purpose:  computes the square  root using Bakhshali method.  


#include <iostream>
#include <string>
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
	cout<< "\nare you wanna repeat again?\ntype 'y' to continue : ";
	cin>>c;
	if(c == 'y')
	return true;
	else
	return false;
}



void calc_sqrt(float num){ //calculate the value of square root
	if (num > 0 ){
	int perfectSqaure = 0;
   int n = 0;
   for (int i = static_cast<int>(num); i > 0; i--) {
      for (int j = 1; j<=i; j++){
         if (j*j == i){
            perfectSqaure = i;
            n = j;
            break;
         }
      }
      if (perfectSqaure > 0)
      break;
   }
   float d = num - perfectSqaure;
   float P = d/(2.0*n);
   float A = n+P;
   float rootOfs = A-((P*P)/(2.0*A));
   cout<< "Square root of " << num <<  " >> " << rootOfs;
	}
	
	else if (num == 0){
		cout<< "square root of 0 >> 0";
	}
	
	else{
		cout<< "sorry there is no square root for this input ";
	}
	
}



void run(){ // run the programme permmenentally
	float number ;
	cout<< "\nplease , enter the number that you want to get its square root : ";
	cin>> number;
	cin.ignore();
	calc_sqrt(number);
	cout<< endl;
	cout<< sepa('-' , 20) << endl;
	if(continued()){
	cout<< sepa('-' , 20) << endl;
	run();
	}
	else{
		cout<< "\nThanks for using....\nBYE";
	exit(0);
	}
}


int main(){
	
	cout<< "    >> Hello user <<";
	run();
	
	
}