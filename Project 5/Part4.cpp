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
	}
	else {
		cout << "1";
	}
}

void Endline() {
	cout << endl;
}

void outputOne() {
	cout << i << " ";
}

int main() {
	//cout << "Elevators will stop at floors no. ";
	_asm {
		mov		ax, 1001000100001100b; //assign random value to ax
		mov		bin, ax;
		shl		x, 15;

	displayBinary:
		mov		ax, bin;
		shl		bin, 1;
		and		ax, x;
		mov		t, ax;
		call	displayBin;
		inc		i;
		cmp		i, 16;
		jne		displayBinary;

	doneDisplay:
		mov		ax, 1001000100001100b; //assign random value to ax
		mov		bin, ax;
		mov		i, 0;

	findElevators:
		cmp		i, 16;
		je		done;
		mov		ax, bin;
		shr		bin, 1;
		and		ax, 1;
		mov		t, ax;
		inc		i;
		cmp		ax, 1;
		je		displayOne;
		jmp findElevators;

	displayOne:
		call outputOne;
		jmp	findElevators;
	done:
		
	}

	system("pause");
	return 0;
}
