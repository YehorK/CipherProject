// MORSE CODE 
//WHEN YOU ENTER THE SENTENCE TO TRANSLATE IT TO MORSE, MAKE SURE TO USE CAPITAL LETTERS!!!

/*
	!-- PROGRAM DESCRIPTION --!
	1. First of all the MorseCodeEncrypt function is exectuted and hence other function are called
	2. The program calls "userInput()" - so user enters his input and it is taken in the format of a string
	3. The "morseCipher()" is called. It's where all calculations happen - the letters and numbers are coded as morse symbols - combinations of dots and dashes.
		3a. The program takes character by character from user's input and compares it to the mapped value. If they match -> the key value is outputed.
			See more in the "toMorse.h". This program is the first time I applied the <map> container of C++ in practice.
		3b. The program asks if user would like to listen to the created morse code and if user enters "Y" -> program goes to the "audio()" function
	4. (in the audio function) The function is programmed to reproduce the combination of dots and dashes in the form of sounds
		4a. First of all, the program takes a pause for 3 seconds so that user has time to turn on the sound.
		4b. The prgram checks every single character and compares it to dot and dash
		4c. If it's a dash - it produces a long sound of 0.9 seconds, if it's a dot -> the sound is 0.4 seconds long
		4d. There is a delay of 0.125 seconds between each dot or dash and there is a 1 second delay between the letters. 
			For example, user enters: "AA" -> in morse it is .-.-
			The audio output for AA would be -->  .(delay 0.125)-(letter delay of 1 second).(delay 0.125)-
	!-- END OF THE PROGRAM --!
*/


#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>  
#include <cstring>
#include <ctime>
#include <map>
#include <windows.h> // WinApi header 
#include "toMorse.h"
#define delay 125
#define frequency 700
#define dotRange 300
#define dashRange 900
#define letterDelay 1000

using namespace std;

vector <string> morseAudio;
string inputText;

void audio();
void morseCipher();
void userInput();
void morseCodeEncrypt(void){
	
	cout << "NB! Make sure you enter the CAPITAL letters!" << endl;

	userInput();
	
	morseCipher();
	
	morseAudio.clear();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void userInput(){
	
	cout << "Please enter the text: ";
	getline(cin, inputText);
	
	cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void morseCipher(){
	
	int len = inputText.size();
	
	for(int i = 0; i < len; i++){
		string str = inputText.substr(i, 1); //taking character by character
		for (auto j = toMorse.begin(); j != toMorse.end(); ++j){ //comparing to the existent values in the <map>
			if(j->second == str){
				cout << j->first;
				morseAudio.push_back(j->first);
			}
		} 
	}
	
	//asking if user would like to listen the audio version of the morse code
	cout << endl;
	char yes;
	char answer;
	
	yes = 'Y';
	
	cout << "Would you like the audio message?(Y/N) ";
	cin >> answer;

	if(yes == answer){
		audio();
	} 
	cout << endl;
}
/////////////////////////////////////////////////////////////////////////
void audio(){
	cout << "Listen! Here is the audio!" << endl;;
	
	Sleep(3000);
	
	string dot;
	dot = '.';
	string dash;
	dash='-';
	
	int total = morseAudio.size();
	for (int i = 0; i < total; i++){
		string element = morseAudio[i];
		int length = element.size();
		for (int j = 0; j < length; j++){
			string temp = element.substr(j, 1);
			if (temp == dot){
				Beep(frequency, dotRange);
				Sleep(delay);
			} else if(temp == dash){
				Beep(frequency, dashRange);
				Sleep(delay);
			} else{
				Sleep(delay); //this delay is used if the character is neither a dot or dash (all letters and numbers are trnasfered to combination of dashes and dots but user also may enter any other signs, but the program will not read them)
			}
		}
		Sleep(letterDelay);
	}
}
