#include <bits/stdc++.h> 
using namespace std; 

string letters_to_Nums(int number, string id, vector <string> &inputByUser){
	
	if (inputByUser[number] == "a" || inputByUser[number] == "A"){
		id = "00001";
	} else if (inputByUser[number] == "b" || inputByUser[number] =="B"){
		id = "00010" ;
	} else if (inputByUser[number] == "c" || inputByUser[number] =="C"){
		id = "00011";
	} else if (inputByUser[number] == "d" || inputByUser[number] =="D"){
		id = "00100";
	} else if (inputByUser[number] == "e" || inputByUser[number] =="E"){
		id = "00101";
	} else if (inputByUser[number] == "f" || inputByUser[number] =="F"){
		id = "00110";
	} else if (inputByUser[number] == "g" || inputByUser[number] =="G"){
		id = "00111";
	} else if (inputByUser[number] == "h" || inputByUser[number] =="H"){
		id = "01000";
	} else if (inputByUser[number] == "i" || inputByUser[number] =="I"){
		id = "01001";
	} else if (inputByUser[number] == "j" || inputByUser[number] =="J"){
		id = "01010";
	} else if (inputByUser[number] == "k" || inputByUser[number] =="K"){
		id = "01011";
	} else if (inputByUser[number] == "l" || inputByUser[number] =="L"){
		id = "01100";
	} else if (inputByUser[number] == "m" || inputByUser[number] =="M"){
		id = "01101";
	} else if (inputByUser[number] == "n" || inputByUser[number] =="N"){
		id = "01110";
	} else if (inputByUser[number] == "o" || inputByUser[number] =="O"){
		id = "01111";
	} else if (inputByUser[number] == "p" || inputByUser[number] =="P"){
		id = "10000";
	} else if (inputByUser[number] == "q" || inputByUser[number] =="Q"){
		id = "10001";
	} else if (inputByUser[number] == "r" || inputByUser[number] =="R"){
		id = "10010";
	} else if (inputByUser[number] == "s" || inputByUser[number] =="S"){
		id = "10011";
	} else if (inputByUser[number] == "t" || inputByUser[number] =="T"){
		id = "10100";
	} else if (inputByUser[number] == "u" || inputByUser[number] =="U"){
		id = "10101";
	} else if (inputByUser[number] == "v" || inputByUser[number] =="V"){
		id = "10110";
	} else if (inputByUser[number] == "w" || inputByUser[number] =="W"){
		id = "10111";
	} else if (inputByUser[number] == "x" || inputByUser[number] =="X"){
		id = "11000";
	} else if (inputByUser[number] == "y" || inputByUser[number] =="Y"){
		id = "11001";
	} else if (inputByUser[number] == "z" || inputByUser[number] =="Z"){
		id = "11010";
	} else if(inputByUser[number] == "."){ 
		id = "11100";
	} else if(inputByUser[number] == ","){ 
		id = "11101";
	} else{
		id = "11111";
	}
	
	return id;
		
}
