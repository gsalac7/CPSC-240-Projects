#include <iostream>

using namespace std;

char c;
int vowels = 0;
void readChar() {
	cin.get(c);
}

void printChar() {
	cout << c;
}

int main() {
	cout << "Enter a sentence: ";
	_asm {
	whileloop:
		call readChar;
		cmp c, 'a';
		je toupper;
		cmp c, 'i';
		je toupper;
		cmp c, 'e';
		je toupper;
		cmp c, 'o';
		je toupper;
		cmp c, 'u';
		je toupper;
		cmp c, '\n';
		je done;

	toupper:
		sub c, 32;
		call printChar;
		jmp whileloop;
	done:

	}
}
