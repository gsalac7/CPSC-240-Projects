#include<iostream>

using namespace std;

short f, c;
char choice;

void continue1() {
	cout << "Continue(y/n)? ";
	cin >> choice;
}

void readData() {
	cout << "Enter the temperature in fahrenheit: ";
	cin >> f;
}

void displayC() {
	cout << f << " F is " << c << " C" << endl;
}

int main() {
	_asm { // convert farenheit to celsius
	forloop:
		call readData;
		mov ax, f; // assign f to eax
		mov bx, 5; // assign this for multipilying
		mov cx, 9; // assign this for dividing
		sub ax, 32; // subtract ax by 32, f - 32
		imul bx; // multply ax by bx, 5(f - 32)
		cwd; // change to 32 bits
		idiv cx; // divide ax by cx, 5(f - 32)/9
		mov c, ax; // assign ax to c
		call displayC;
		call continue1;
		cmp choice, 'y';
		je forloop;
	done:

	}
}
