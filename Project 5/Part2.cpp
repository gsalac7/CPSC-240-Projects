/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 2
*/
#include <iostream>

using namespace std;
char choice;
short pin;

void readData() {
	cout << "Enter a four digit integer PIN number: ";
	cin >> pin;
}

void continue1() {
	cout << "Do you want to try again(y/n): ";
	cin >> choice;
}

void displayValid() {
	cout << pin << " is a valid pin number\n";
}

void displayNotValid() {
	cout << pin << " is not a valid pin number\n";
}

int main() {
	_asm {
	forloop:
		call	readData; //read the data
		mov		dx, 0; //move 0 to dx register
		mov		ax, pin; //move pin to the ax register
		mov		bx, 2; 
		idiv	bx; //divide pin by two
		cmp		dx, 0; //check if remainder is 0
		je		valid; //if it is, then it's even then its valid
		jmp		notValid; //else its not valid
	valid: //valid then ask to continue
		call	displayValid;
		jmp		continue2;
	notValid: //not valid then ask to continue
		call	displayNotValid; 
	continue2: //if choice is y then continue else stop
		call	continue1;
		cmp		choice, 'y';
		je		forloop;
	done:
	}
	return 0;
}
