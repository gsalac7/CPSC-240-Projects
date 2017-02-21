/*Angelo Salac
Michael Busslinger
2/23/16
Project 4, Part2
*/
#include <iostream>
using namespace std;

char c;

//function for reading char
void readChar() {
	cin.get(c);
}

//print char
void printChar() {
	cout << c;
}

int main() {
	cout << "Enter a sentence: ";
	_asm {
	whileloop: //create a loop for reading the chars
		call	readChar; //call read char function
		cmp		c, '.'; //compare char with '.'
		je		done; //if its equal then its done reading
		cmp		c, 'a'; //compare the char with every vowel
		je		ifV;
		cmp		c, 'e';
		je		ifV;
		cmp		c, 'i';
		je		ifV;
		cmp		c, 'o';
		je		ifV;
		cmp		c, 'u';
		je		ifV;
		call	printChar; //print the character if it's not a vowel.
		jmp		whileloop; //repeat
	ifV:
		sub		c, 32; //subtract the char to get the upper case vowels
		call	printChar; //print the char
		jmp		whileloop; //go back to the loop
	done: //finished
	}
	cout << endl;
}
