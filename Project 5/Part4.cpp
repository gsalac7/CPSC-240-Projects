/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 3
*/
#include <iostream>

using namespace std;
short bin, counter = 0, i = 0, t, x = 1;

void displayBin() {
	if (t == 0) {
		cout << "0";
	} else {
		cout << "1";
	}
}

void Endline() {
	cout << endl;
}

void outputOne() {
	cout << i << " ";
}

void elevators() {
	cout << "Elevator will stop at floors no. ";
}

int main() {
	cout << "AX = ";
	_asm {
		mov		ax, 1001000100001100b; //assign random value to ax
		mov		bin, ax;
		shl		x, 15;

	displayBinary:
		mov		ax, bin; //assign bin to ax
		shl		bin, 1; //shift bin left 1
		and		ax, x; //compare ax with x
		mov		t, ax; //move ax to t
		call	displayBin; //display 1 or 0
		inc		i; //add 1 to i
		cmp		i, 16; //check if i is 16 if it is then stop
		jne		displayBinary; //loop

	doneDisplay:
		mov		ax, 1001000100001100b; //assign random value to ax
		mov		bin, ax;
		mov		i, 16; //give i a new value of 16 

		call	Endline;
		call	elevators;

	findElevators:
		cmp		i, 0; //check if i is 0 if it is stop the loop
		je		done; 
		mov		ax, bin; //move bin to ax
		shl		bin, 1; //move bin left 1
		and		ax, x; //check if ax is 1 or 0 at the left
		shr		ax, 15; //shift it right 15
		cmp		ax, 1; //to compare it to 1
		je		displayOne; //if its 1 then display the index
		dec		i; //decrement
		jmp		findElevators; //loop
 
	displayOne:
		call	outputOne;
		dec		i;
		jmp		findElevators;
	done:
		call	Endline;
	}

	system("pause");
	return 0;
}
