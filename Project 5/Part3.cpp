/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 3
*/
#include <iostream>

using namespace std;
short bin, counter = 0, i = 0, l;

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

void Endline() {
	cout << endl;
}

void outputOne() {
	cout << i << " ";
}

void display() {
	cout << counter << " Sprinklers are ON" << endl;
}

int main() {
	_asm {
		mov		ax, 0110101000101111b; //assign random value to ax
		mov		bin, ax;

	displayBinary:
		cmp		i, 16;
		je		done;
		mov		ax, bin;
		inc		i;
		shr		bin, 1;
		and		ax, 1;
		cmp		ax, 0;
		je		sprinklers;
		jmp		displayBinary;
	sprinklers:
		call	outputOne;
		jmp		displayBinary;
	
	done:
		call	Endline;
		mov		i, 0;
		mov		ax, 0110101000101111b; //assign random value to ax
		mov		bin, ax;

	Counter:
		cmp		i, 16;
		je		finished;
		mov		ax, bin;
		inc		i;
		shr		bin, 1;
		and		ax, 1;
		cmp		ax, 1;
		je		AddOne;
		jmp		Counter;
	AddOne:
		inc		counter;
		jmp		Counter;
	finished:
		call	display;
	}

	system("pause");
	return 0;
}
