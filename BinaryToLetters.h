#include <bits/stdc++.h> 
using namespace std; 

string BinaryToLetters(string str){
	
	if(str == "00001"){
		return "a";
	} else if (str == "00010"){
		return "b";
	} else if (str == "00011"){
		return "c";
	} else if (str == "00100"){
		return "d";
	} else if (str == "00101"){
		return "e";
	} else if (str == "00110"){
		return "f";
	} else if (str == "00111"){
		return "g";
	} else if (str == "01000"){
		return "h";
	} else if (str == "01001"){
		return "i";
	} else if (str == "01010"){
		return "j";
	} else if (str == "01011"){
		return "k";
	} else if (str == "01100"){
		return "l";
	} else if (str == "01101"){
		return "m";
	} else if (str == "01110"){
		return "n";
	} else if (str == "01111"){
		return "o";
	} else if (str == "10000"){
		return "p";
	} else if (str == "10001"){
		return "q";
	} else if (str == "10010"){
		return "r";
	} else if (str == "10011"){
		return "s";
	} else if (str == "10100"){
		return "t";
	} else if (str == "10101"){
		return "u";
	} else if (str == "10110"){
		return "v";
	} else if (str == "10111"){
		return "w";
	} else if (str == "11000"){
		return "x";
	} else if (str == "11001"){
		return "y";
	} else if (str == "11010"){
		return "z";
	} else if (str == "11100"){
		return ".";
	} else if (str == "11101"){
		return ",";
	}else{
		return " ";
	}
}
