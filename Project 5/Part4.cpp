/*Angelo Salac
Michael Busslinger
3/2/17
Project 5, Part 4
*/
#include <iostream>

using namespace std;
short a = 5, b = 7;
short bin, counter = 0;

void displayAX() {
	short x = 1, t;
	for (int i = 1; i <= 16; i++) {
		t = bin&x;
		if (t == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
		if ((i % 4) == 0) {
			cout << " ";
		}
		bin = bin >> 1;
	}

	cout << endl;
}

void countAX()  {
	short x = 1, t;
	cout << "Elevator will stop at floors no. ";

	for (int i = 1; i <= 16; i++) {
		t = bin&x;
		if (t == 1) {
			cout << i << " ";
		}
		bin = bin >> 1;
	}
	cout << endl;
}

int main() {
	_asm {
		mov ax, 1001000100001100b;
		mov bin, ax;
		call displayAX;
		mov ax, 1001000100001100b;
		mov bin, ax;
		call countAX;

	}

	return 0;
}
