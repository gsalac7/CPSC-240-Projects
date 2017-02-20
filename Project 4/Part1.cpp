#include <iostream>

using namespace std;

int i = 0, yesCounter = 0, noCounter = 0;
char c;
void printStar() {
	cout << "*";
}
void readData() {
	cin >> c;
}

void yesVotes() {
	cout << "No. of YES votes = " << yesCounter << " ";
	_asm {
		mov yesCounter, eax;
	forloop:
		call printStar;
		inc i;
		cmp i, eax;
		je done;
		jmp forloop;
	done:
		mov i, 0;
	}
	cout << endl;
}

void noVotes() {
	cout << "No. of NO votes = " << noCounter << " ";
	_asm {
		mov noCounter, eax;
	forloop:
		call printStar;
		inc i;
		cmp i, eax;
		je done;
		jmp forloop;
	done:
		mov i, 0;
	}
	cout << endl;
}

int main() {
	cout << "Enter a string of votes: ";
	_asm {
	forloop:
		call readData;
		cmp c, 'y';
		je addY;
		jmp addN;
	addY:
		inc yesCounter;
		inc i;
		cmp i, 10;
		je done;
		jmp forloop;

	addN:
		inc noCounter;
		inc i;
		cmp i, 10;
		je done;
		jmp forloop;

	done:	
		call yesVotes;
		call noVotes;

	}

	return 0;
}
