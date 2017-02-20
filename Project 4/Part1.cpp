#include <iostream>

using namespace std;

char c[10];
int i = 0, yesCounter = 0, noCounter = 0;
void readData() {
	cin >> c[i];
}

void yesVotes() {
	cout << "No. of YES votes = " << yesCounter << endl;
}

void noVotes() {
	cout << "No. of NO votes = " << noCounter << endl;
}

int main() {
	cout << "Enter a string of votes: ";
	_asm {
	forloop:
		call readData;
		inc i;
		cmp i, 10;
		jne forloop;
	done:
		mov i, 0;
		cmp c[i], 'y';
		je addY;
		cmp c[i], 'n';
		je addN;
	addY:
		inc yesCounter;
		inc, i;
		jmp done;
	addN:
		inc noCounter;
		inc, i;
		jmp done;
	}

	return 0;
}
