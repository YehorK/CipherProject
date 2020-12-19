//CAESAR CIPHER
//So far the limit of the input for this cipher is 4094 characters, which is approximately equal to 580 words

/*
	!-- PROGRAM DESCRIPTION --!
	* 
	* 1. There are two functions (which are called from the main.cpp depending on the user's choice)
	* 	 If user decides to encrypt, then the caesarCipherEncrypt() is called. If decrypt -> caesarCipherDecrypt().
	* 2. In both cases (encrypt or decrypt) the input function is called in order to allow user to enter the message as well as the key for shift
	* 	 The key must be a positive integer or  zero. If user enters negative - the program will ask to re-enter the key.
	* 	 English alphabet has 26 letters. However, if user enters any number bigger than 26 for the key -> 
	* 	 -> the program will subtract 26 from the entered number until the key is in the range of 1-26. 
	* 3. In case of encryption the comparingLettersCiphering() function is called, for decryption - Deciphering() fucntion is used.
	* 4. In both cases the program refers to the "letters_to_ID.h" and "IDs_to_letters.h" files for convertion between letters and numbers
	* 5. Eventually, in both cases a fullOutput() function is called to output the result.
	* 
	!-- END OF THE PROGRAM --!

*/

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>  
#include <cctype>
#include <locale>   
#include <cstring>
#include <bits/stdc++.h> 
#include "letters_to_ID.h"
#include "IDs_to_letters.h"

using namespace std;

vector<string> v;
vector<string> encoded;
void fullOutput(int);
void Deciphering(int, int);
void comparingLettersCiphering(int, int);
int input(int*); //the function allows user to input the text, which will be coded and also as the other parameter it allows to enter the key (call by address)
void caesarCipherEncrypt(void){ //this function runs only if user decided to encryt the message
	
	int total, key;
	int i;
	
	//input function
	total = input(&key);
 
	for(i = 0; i < total; i++){
		comparingLettersCiphering(i, key);
	}
	cout << endl;
	cout << "Here is your encryption:" << endl;
	
	fullOutput(total);
	
    v.clear();
    encoded.clear();
}
////////////////////////////////////////////////////////////////////////
void caesarCipherDecrypt(void){ //this function runs only if user chose to decryt the message
		
	int total, key;
	int i;
	
	//input function
	total = input(&key);
 
	for(i = 0; i < total; i++){
		Deciphering(i, key);
	}
	
	cout << endl;
	cout << "Here is your decryption:" << endl;
	
	fullOutput(total);
	   
    v.clear();
    encoded.clear();
}
////////////////////////////////////////////////////////////////////////
int input(int *key){
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
	
	int i;
		
	cout << endl;
	
	//Inputing
	string userInput;
	string word;
    cout << "Enter the text: ";
    getline(cin, userInput);
	
    vector<string>::iterator it;
	
	//Storing the text letter by letter in the <vector> v
    int length = userInput.length(); 
    for( i=0; i < length; i++ ){
		v.push_back( string(sizeof(char),userInput[i]) ); // Convert char * to string
	}
	
	//Entering the key
	cout << endl;
	do{
		cout << "Enter the key: ";
		cin >> *key;
	}while(*key < 0);
	
	 while(*key > 26){
		*key = *key - 26;
	}

    return length;
	
}
////////////////////////////////////////////////////////////////////////
void comparingLettersCiphering(int number, int key){
	
	int id = 0;
	int shift;
	string tempStr;
	
	//ADD the alphabet
	id = letters_to_ID(number, id, v);
	
	if (id != 123){
		shift = id + key;
		
		if (shift > 26){
			shift = shift - 26;
		}
		
		tempStr = IDs_to_letters(shift);
		encoded.push_back(tempStr);

	
	} else {
		encoded.push_back(v[number]);
	}

}
/////////////////////////////////////////////////////////////////////////
 void Deciphering(int number, int key){
	 	
	int id = 0;
	int shift;
	string tempStr;
	
	//ADD the alphabet
	id = letters_to_ID(number, id, v);
	
	if (id != 123){
		shift = id - key;
		
		if (shift < 1){
			shift = shift + 26;
		}
		
		tempStr = IDs_to_letters(shift);
		encoded.push_back(tempStr);

	
	} else {
		encoded.push_back(v[number]);
	}

}
////////////////////////////////////////////////////////////////////////
void fullOutput(int total){
	
	for(int j=0; j < total; j++){
		cout << encoded[j];
	}
	
}
