/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 3
*/
#include <iostream>

using namespace std;
short a = 5, b = 7;
short bin, counter = 0;

void countOnes() {
	short x = 1;
	short t;
	for (int i = 1; i <= 16; i++) {
		t = bin&x;
		if (t == 1) { //every time we encounter a 1, then increment the counter
			counter++;
		}
		bin = bin >> 1; 
	}
	cout << counter << " sprinklers are ON" << endl;
}

void displaySprinklers() {
	short x = 1;
	short t;
	cout << "Defective sprinklers: ";
	for (int i = 1; i <= 16; i++) {
		t = bin&x;
		if (t == 0) { //every time we encounter a 0, then output the index
			cout << i << " ";
		}
		bin = bin >> 1;
	}
	cout << endl;
}

void displayBin() {
	short x = 1 << 15;
	short t;
	for (int i = 1; i <= 16; i++) {
		t = bin&x;
		if (t == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
		if (i % 4 == 0) {
			cout << " ";
		}
		bin = bin << 1;
	}
	cout << endl;
}

int main() {
	_asm {
		mov		ax, 0110101000101111b; //assign random value to ax
		mov		bin, ax;			//move ax to bin
		call	displayBin;			//call display Bin function
		mov		ax, 0110101000101111b;
		mov		bin, ax;
		call	countOnes;
		mov		ax, 0110101000101111b;
		mov		bin, ax;
		call	displaySprinklers;
	}

	return 0;
}
