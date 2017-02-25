/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 1
*/
#include <iostream>

using namespace std;

//functions for displaying all possible values
void DisplayThreePrints() {
	cout << "a.\tThere are a total of 3 printers connected to the computer\n";
}

void DisplayTwoPrints() {
	cout << "a.\tThere are a total of 2 printers connected to the computer\n";
}

void DisplayOnePrints() {
	cout << "a.\tThere is a total of 1 printer connected to the computer\n";
}

void DisplayZeroPrints() {
	cout << "a.\tThere are a total of 0 printers connected to the computer\n";
}

void DisplayThreeDrives() {
	cout << "b.\tThere are a total of 3 floppy drives\n";
}

void DisplayTwoDrives() {
	cout << "b.\tThere are a total of 2 floppy drives\n";
}

void DisplayOneDrives() {
	cout << "b.\tThere is a total of 1 floppy drive\n";
}

void DisplayZeroDrives() {
	cout << "b.\tThere are a total of 0 floppy drives\n";
}

void DisplaySixFour() {
	cout << "c.\t64K RAM\n";
}

void DisplayFourEight() {
	cout << "c.\t48K RAM\n";
}

void DisplayThreeTwo() {
	cout << "c.\t32K RAM\n";
}

void DisplayOneSix() {
	cout << "c.\t16K RAM\n";
}

int main() {
	int c;
	_asm {
	//first check how many printers there are
	checkPrinters:
		mov		ax, 1100111010011100b; //assign random value for ax
		and		ax, 1100000000000000b; //check to see how many printers is connected
		cmp		ax, 1100000000000000b; //compare to see if how many printers
		je		threePrint;
		cmp		ax, 1000000000000000b;
		je		twoPrint;
		cmp		ax, 0100000000000000b;
		je		onePrint;
		jmp		zeroPrint;

	//labels for displaying the number of printers
	threePrint:
		call DisplayThreePrints;
		jmp checkFloppy;
	twoPrint:
		call DisplayTwoPrints;
		jmp checkFloppy;
	onePrint:
		call DisplayOnePrints;
		jmp checkFloppy;
	zeroPrint:
		call DisplayZeroPrints;
	//now check how many floppy drives
	checkFloppy:
		mov		ax, 1100111010011100b; //assign same random value for ax
		and		ax, 0000000011000000b;  //check to see bit values for the floppy drives
		cmp		ax, 0000000011000000b; //compare all possible bit values
		je		threeDrives;
		cmp		ax, 0000000010000000b;
		je		twoDrives;
		cmp		ax, 0000000001000000b;
		je		oneDrive;
		jmp		zeroDrives;
	//labels for displaying the number of drives
	threeDrives:
		call	DisplayThreeDrives;
		jmp		checkRam;
	twoDrives:
		call	DisplayTwoDrives;
		jmp		checkRam;
	oneDrive:
		call	DisplayOneDrives;
		jmp		checkRam;
	zeroDrives:
		call	DisplayZeroDrives;
	//now check the ram
	checkRam:
		mov		ax, 1100111010011100b; //assign same random value for ax
		and		ax, 0000000000001100b; //check to see the bit values for the RAM
		cmp		ax, 0000000000001100b; //compare all possible values for RAM
		je		SixFour;
		cmp		ax, 0000000000001000b;
		je		FourEight;
		cmp		ax, 0000000000000100b;
		je		ThreeTwo;
		jmp		OneSix;
	//labels for displaying the RAM
	SixFour:
		call	DisplaySixFour;
		jmp		done;
	FourEight:
		call	DisplayFourEight;
		jmp		done;
	ThreeTwo:
		call	DisplayThreeTwo;
		jmp		done;
	OneSix:
		call	DisplayOneSix;

	done:
	}

	return 0;
}
