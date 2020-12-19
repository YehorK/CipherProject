/*
	THIS IS THE MAIN FILE - > PLEASE COMPLINE AND RUN IT (furhter just follow the on screen instructions)
	* DO NOT TRY TO RUN THE OTHER FILES (THEY MISS MAIN FUNCTION)
	* THE OTHER FILES ARE CONNECTED TO THIS main.cpp 

*/

#include <iostream>
#include <stdlib.h>
#include "binaryFunctions.cpp"
#include "MorseFunctions.cpp"
#include "CaesarFunctions.cpp"
using namespace std;
int cipherChoice();
int action();
void binaryCipherEncrypt();
int main(void)
{
	int number1, number2; 
	number1 = cipherChoice(); //if chooses the cipher
	
	if (number1 == 1 || number1 == 2){
		number2 = action(); //user chooses to encrypt or decrypt (this is applicable only to caesar and binary ciphers)
	}
	
	switch(number1){
		case 1:
			if(number2 == 1){
				caesarCipherEncrypt();
			} else{
				caesarCipherDecrypt();
			}
			break;
		case 2: 
			if(number2 == 1){
				binaryCipherEncrypt();
			} else{
				binaryCipherDecrypt();
			}
			break;
		case 3:
			morseCodeEncrypt();
			break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cipherChoice(){
	int number;
	
	cout << "Welome to Yehor's Ciphers!" << endl;
	cout << "There are three ciphers available in total!" << endl;
	cout << "Please enter a number that corresponds to the cipher that you want to use!" << endl;
	cout << "Caesar - 1" << endl;
	cout << "Binary - 2" << endl;
	cout << "Morse - 3" << endl;
	cout << endl;
	
	do{
		cout << "Your choice for cipher: ";
		cin >> number;
	}while(number < 1 || number > 3);
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
	
	cout << endl;
	
	return number;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int action(){
	
	int num;
	
	cout << "You can encrypt or decrypt the data!" << endl;
	cout << "If you wish encrypt - enter 1. If decrypt - enter 2" << endl;
	do{
		cout << "Your choice for action: ";
		cin >> num;
	}while(num < 1 || num > 2);
	
	return num;
}
