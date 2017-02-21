/*Angelo Salac
Michael Busslinger
2/23/17
Project 4, Part 4
*/
#include<iostream>

using namespace std;

short f, c;
char choice;

void continue1() {
	cout << "Continue(y/n)? ";
	cin >> choice;
}

void readData() {
	cout << "Enter the temperature in fahrenheit: ";
	cin >> f;
}

void displayC() {
	cout << f << " F is " << c << " C" << endl;
}

int main() {
	_asm { // convert farenheit to celsius
	forloop:
		call	readData;
		mov		ax, f; // assign f to eax
		mov		bx, 5; // assign this for multipilying
		mov		cx, 9; // assign this for dividing
		sub		ax, 32; // subtract ax by 32, f - 32
		imul	bx; // multply ax by bx, 5(f - 32)
		cwd;		// change to 32 bits
		idiv	cx; // divide ax by cx, 5(f - 32)/9
		mov		c, ax; // assign ax to c
		call	displayC; //display the Celsiuss
		call	continue1; //ask to continue
		cmp		choice, 'y'; //if yes the repeat the loop
		je		forloop;
	done: //else finished
	}
	return 0; 
}
