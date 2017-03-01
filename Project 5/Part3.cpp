/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 3
*/
#include <iostream>

using namespace std;
short bin, counter = 0, i = 0, x = 1, t, j = 16;

void Endline() {
	cout << endl;
}

void outputOne() {
	cout << i << " ";
}

void defectiveSprinkler() {
	cout << "The defective sprinklers are: ";
}

void display() {
	cout << counter << " Sprinklers are ON" << endl;
}

void displayBin() {
	if (t == 0) {
		cout << "0";
	} else {
		cout << "1";
	}
}

void endline() {
	cout << endl;
}

int main() {
	cout << "AX = ";
	_asm {
		mov		ax, 0x6A2F; //assign random value to ax
		mov		bin, ax;
		shl		x, 15;

	displayBinary:
		mov		ax, bin; //move bin to ax
		shl		bin, 1; //shift bin left by 1
		and		ax, x; //check first value of ax
		mov		t, ax; //display bin of 1 or 0
		call	displayBin;
		inc		i; //increment i
		cmp		i, 16; //stop at 16 bits
		jne		displayBinary;

		call	endline;

		mov		ax, 0x6A2F; //assign random value to ax
		mov		bin, ax;
		mov		i, 16;
		call	defectiveSprinkler;

	displayDefectiveSprinklers:
		cmp		i, 0;	//if i == 0 then stop the loop
		je		done;  //stop loop
		mov		ax, bin; //move binary to ax
		shl		bin, 1; //shift the binary left by 1
		and		ax, x; //find the first value
		shr		ax, 15; //shift ax right 15 so it becomes 1 or 0
		cmp		ax, 0; //check if ax is 0, if it is, then output i index
		je		sprinklers;
		dec		i; //decrement i
		jmp		displayDefectiveSprinklers; //looop again
	sprinklers:
		call	outputOne; //output i
		dec		i; //decrement
		jmp		displayDefectiveSprinklers; //back to loop

	done:
		call	Endline;
		mov		i, 0;
		mov		ax, 0x6A2F; //assign random value to ax
		mov		bin, ax;

	Counter:
		cmp		i, 16; //check if i is 0
		je		finished; //then finish
		mov		ax, bin; //move bin to ax
		inc		i; //increment i
		shr		bin, 1; //shift bin right 1
		and		ax, 1; //check value of ax
		cmp		ax, 1; //check if its 1
		je		AddOne; //if it is add to the counter
		jmp		Counter; //loop
	AddOne:
		inc		counter;
		jmp		Counter;
	
	finished:
		call	display;
	}

	system("pause");
	return 0;
}
