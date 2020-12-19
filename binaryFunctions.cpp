//BINARY CIPHER
// the code doesn't support if you enter numbers - program will output just a space instead of a number or any other symbol except dot or coma
/*
	!-- PROGRAM DESCRIPTION --!
	
	The program is based on XNOR. The  truth table in this case is as following: 
	* 1 - 1 = 1
	* 0 - 0 = 1
	* 0 - 1 = 0
	* 1 - 0 = 0
	
	The program doesn't have a "pre-established" limited for the user's input. At the moment it is limited to the amount of input that console can take in
	* The limit is 4094 characters, which is approximately equal to 580 words.
	* It is the amount of input thay program/terminal takes in one run - it doesn't crash but just doesn't allow to take in more 
	
	(if user decided to encrypt the data)
	* 1. The "binaryCipherEncrypt()" is called
	* 2. The input function is called -> it allows user to enter the message
	* 3. "letterToBinary()" function is called where the data entered by user is transfered to compare with the "comparison list"
	* 	 in "letters_to_Nums.h" in order to bring the binary strings back
	* 4. The "cipherReady()" function is where random array is generated
	* 5. After that the program goes to function "cipherBuild()" -> thats where from the actual and random array are compared in order to calculage the key array 
	* 6. The last function is "outputEncrypt()" -> it outputs the data to the terminal screen as well as to the text files
	
	(if user decided to decrypt the data)
	* 1. The deciphering process is slightly simpler than encrypting. Initially, the "binaryCipherDecrypt()" is called
	* 	 The decrypting process is such that the values of Key and Random are taken from the respective text files
	* 2. Thence "Deciphering()" is called. This function checks if files "key.txt" and "random.txt" exist. If not - the program returns 0. 
	* 	 It they exist - the program opens and takes from each character by character. 
	* 	 Then, those characters are compared. In case if they match 1 is added to a deciphering string. If they do not match - 0 is added.
	* 3. When the decrypted binary code is obtained, the program in the function inTOString() compares it to the codes in BinaryToLotters.h to get the letters.
	* 4. The program goes to the outputDecrypt and outputs the actual message to the screen.
	
	!-- END OF THE PROGRAM --!
*/


#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <stack> 
#include <cctype>  
#include <cstring>
#include <ctime>
#include "letters_to_Nums.h"
#include "BinaryToLetters.h"
using namespace std;

stack<string> decodedMessage;
stack<string> decipherToCompare;
string decrypting;
vector<int> fullEncryptedRandom;
vector<int> fullEncryptedKey;
vector<string> inputByUser;
vector<string> binary;

void outputDecrypt(int);
void intToString();
void Deciphering(); 
void outputEncrypt(); //outputing to the txt files and to the terminal
void cipherBuild(int[], int[]); //building the Key array based on the random array and actual binary (that is made from letters)
void cipherReady(int); //trnasforming the string of binary into the actual digits (of binary code), also generate the random array
void letterToBinary(int); //transforming letters into the binary code
int inputEncrypt(); //the function allows user to input the text, which will be coded (call by address)
void binaryCipherDecrypt (void);
void binaryCipherEncrypt (void){ //this function is called if user has chosen to ENCRYPT the data
	
	srand(time(NULL));
	
	int total;
	int i = 0;
	
	//input function
	total = inputEncrypt();
  
	//Calculating 
	for(i = 0; i < total; i++){
		letterToBinary(i);
	}
	cout << endl;
	outputEncrypt();
     
    fullEncryptedKey.clear();
    fullEncryptedRandom.clear();
    inputByUser.clear();
    binary.clear();
}
////////////////////////////////////////////////////////////////////////
void binaryCipherDecrypt (void){ //this function is called if user has chosen to DECRYPT the data
	
	srand(time(NULL));
	
	Deciphering();	
	cout << endl;
	intToString();

}
////////////////////////////////////////////////////////////////////////

int inputEncrypt(){
	
	int i;
	cout << endl;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
	
	//Inputing
	string userInput;
	string word;
    cout << "Enter the text: ";
    getline(cin, userInput);
	
    vector<string>::iterator it;
	
	//Storing the text letter by letter in the <vector> inputByUser
    int length = userInput.length(); 
    for( i=0; i < length; i++ ){
		inputByUser.push_back( string(sizeof(char),userInput[i]) ); // Convert char * to string
	}
    
    return length;
	
}
////////////////////////////////////////////////////////////////////////
void letterToBinary(int number){
	string id;
	
	//Transfer the letters into the binary
	id = letters_to_Nums(number, id, inputByUser);
	
	binary.push_back(id);	
	
	cipherReady(number);
}
/////////////////////////////////////////////////////////////////////////
void cipherReady(int num){
	
	//transfering my string of digits into the integer type
	string str;
	str = binary[num];
	stringstream digitalString(str);
	int digits = 0;
	digitalString >> digits;

	//inputting the integers into the array considr
	int tempNum;
	int arr[5];
	
	for(int i = 0; i < 5; i++){
		tempNum = digits%10;
		digits = digits/10;
		arr[4-i] = tempNum;
		}
	
	//Getting the random array
	int arrRandom[5];
	int randomDigit;
	
	for(int i = 0; i < 5; i++){
		randomDigit = rand() % 2;
		arrRandom[4-i] = randomDigit; 
	}
	
	cipherBuild(arr, arrRandom);
	
}
//////////////////////////////////////////////////////////////////////////
void cipherBuild(int arrayReal[], int arrayRandom[]){
	int temp1, temp2;
	for (int i=0; i < 5; i++){
		temp1 = arrayReal[i];
		temp2 = arrayRandom[i];
		
		fullEncryptedRandom.push_back(temp2);
		
		if(temp1 == temp2){
			fullEncryptedKey.push_back(1);
		} else{
			fullEncryptedKey.push_back(0);
		}
	}	

}
/////////////////////////////////////////////////////////////////////////
void outputEncrypt(){
	
	int i;
	
	int arrSizeKey = fullEncryptedKey.size();
	int arrSizeRandom = fullEncryptedRandom.size();
	
	cout << "Your Key: " << endl;
	for(i = 0; i < arrSizeKey; i++){
	cout << fullEncryptedKey[i];
	}
	
	cout << endl;
	cout << endl;
	
	cout << "Your Random: " << endl;
	for(i = 0; i < arrSizeRandom; i++){
	cout << fullEncryptedRandom[i];	
	}
	
	ofstream keyFile("key.txt");
	ofstream randomFile("random.txt");
	
	for(i = 0; i < arrSizeKey; i++){
		keyFile << fullEncryptedKey[i];
	}
	
	for(i = 0; i < arrSizeRandom; i++){
		randomFile << fullEncryptedRandom[i];	
	}	
	
	cout << endl;
	cout << endl;
	cout << "The data is also printed to key.txt and random.txt files" << endl;
	
	keyFile.close();
	randomFile.close();
}
/////////////////////////////////////////////////////////////////////////
void Deciphering(){
		
	ifstream keyFile;
	keyFile.open("key.txt");
	ifstream randomFile;
	randomFile.open("random.txt");
	
	//handling the case if one of the text files for decryption is missing
	if(keyFile.fail()){
		cout << "Key file doesn't exist! Try again!";
		return;
	}
	if(randomFile.fail()){
		cout << "Random file doesn't exist! Try again!";
		return;
	}
	
	char aKey, aRandom;
	while (!keyFile.eof()) {
		keyFile >> aKey;
		randomFile >> aRandom;
		if(aKey == aRandom){
			decrypting += "1";
		} else{
			decrypting += "0";
		}
	} 
	
	decrypting.pop_back(); //for some reason, the deciphering loop in the end gives one extra element, so this line of code removes it

}
////////////////////////////////////////////////////////////////////////
void intToString(){
	
	int len = decrypting.size();
	int length = len/5;
	for(int i = 0; i < len; i+=5){
		string str = decrypting.substr(i,5);
		decipherToCompare.push(str);
	}	
	
	outputDecrypt(length);
}
/////////////////////////////////////////////////////////////////////////
void outputDecrypt(int len){
	
	int i;
	
	for(i = 0; i < len; i++){
		string str1 = decipherToCompare.top();
		string str2 = BinaryToLetters(str1);
		decodedMessage.push(str2);
		decipherToCompare.pop();
	}
	
	while(!decodedMessage.empty()){
		cout << decodedMessage.top();
        decodedMessage.pop();
	}
		
}
