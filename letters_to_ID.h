//The file is made to search for the letter and return its ID (the number)

#include<bits/stdc++.h> 
using namespace std; 

int letters_to_ID(int number, int id, vector <string> &v){
	if (v[number] == "a" || v[number] == "A"){
		id = 1;
	} else if (v[number] == "b" || v[number] =="B"){
		id = 2;
	} else if (v[number] == "c" || v[number] =="C"){
		id = 3;
	} else if (v[number] == "d" || v[number] =="D"){
		id =4;
	} else if (v[number] == "e" || v[number] =="E"){
		id = 5;
	} else if (v[number] == "f" || v[number] =="F"){
		id = 6;
	} else if (v[number] == "g" || v[number] =="G"){
		id = 7;
	} else if (v[number] == "h" || v[number] =="H"){
		id = 8;
	} else if (v[number] == "i" || v[number] =="I"){
		id = 9;
	} else if (v[number] == "j" || v[number] =="J"){
		id = 10;
	} else if (v[number] == "k" || v[number] =="K"){
		id = 11;
	} else if (v[number] == "l" || v[number] =="L"){
		id = 12;
	} else if (v[number] == "m" || v[number] =="M"){
		id = 13;
	} else if (v[number] == "n" || v[number] =="N"){
		id = 14;
	} else if (v[number] == "o" || v[number] =="O"){
		id = 15;
	} else if (v[number] == "p" || v[number] =="P"){
		id =16;
	} else if (v[number] == "q" || v[number] =="Q"){
		id = 17;
	} else if (v[number] == "r" || v[number] =="R"){
		id =18;
	} else if (v[number] == "s" || v[number] =="S"){
		id = 19;
	} else if (v[number] == "t" || v[number] =="T"){
		id = 20;
	} else if (v[number] == "u" || v[number] =="U"){
		id = 21;
	} else if (v[number] == "v" || v[number] =="V"){
		id = 22;
	} else if (v[number] == "w" || v[number] =="W"){
		id = 23;
	} else if (v[number] == "x" || v[number] =="X"){
		id = 24;
	} else if (v[number] == "y" || v[number] =="Y"){
		id = 25;
	} else if (v[number] == "z" || v[number] =="Z"){
		id = 26;
	} else{
		id = 123;
	}
	
	return id;
		
}
