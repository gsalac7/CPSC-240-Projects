#include <iostream>

using namespace std;

int i = 0, yesCounter = 0, noCounter = 0;
char c;

void printStar() {
	cout << "*";
}
void readData() {
	cin.get(c);
}

void yesVotes() {
	cout << "No. of YES votes = " << yesCounter << " ";
	_asm {
		mov i, 0;
	forloop:
		call printStar;
		inc i;
		mov eax, i;
		cmp eax, yesCounter;
		jne forloop;
	done:

	}

	cout << endl;
}

void noVotes() {
	cout << "No. of NO votes = " << noCounter << " ";
	_asm {
		mov i, 0;
	forloop:
		call printStar;
		inc i;
		mov eax, i;
		cmp eax, noCounter;
		jne forloop;
	done:

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
